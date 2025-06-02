set<string> blockedPreprocessor = {
    "Constructor",
    "Destructor",
    "SonolusApi",
    "Blocked",
    "NonType",
    "CppLoop"
};

set<string> needBlockedFunction = {
    "abs", "exp", "log", "pow", "sqrt", "cbrt", "hypot",
    "sin", "cos", "tan", "asin", "acos", "atan", "atan2",
    "sinh", "cosh", "tanh", "asinh", "acosh", "atanh",
    "erf", "erfc", "tgamma", "lgamma", "ceil", "floor", "trunc", "round", "nearbyint", "rint",
    "frexp", "ldexp", "modf", "scalbn", "ilogb", "logb", "nextafter", "copysign",
    "fpclassify", "isfinite", "isinf", "isnan", "isnormal", "signbit", "isgreater", "isgreaterequal", "isless", "islessequal", "islessgreater", "isunordered",

    "at", "front", "back", "data",
    "begin", "cbegin", "end", "cend", "rbegin", "crbegin", "rend", "crend",
    "empty", "size", "reserve", "capacity",
    "clear", "insert", "emplace", "erase", "swap", "extract", "merge", "push_back", "emplace_back", "pop_back", "push_front", "emplace_front", "pop_front", "resize",
    "count", "find", "contains", "lower_bound", "upper_bound"
};

set<string> userDefinedFunction;

string solveClass(string name, string code, SourceInfo sourceInfo) {
    string res = "class " + name + "{" + code + "}";
    // cout << sourceInfo.file << ":" << sourceInfo.line << ":" << sourceInfo.pre + 1 << endl;
    // cout << "Used: class " << name << " {" << code << "}" << endl;
    return res;
}

string solveStruct(string name, string code, SourceInfo sourceInfo) {
    string res = "struct " + name + "{" + code + "}";
    // cout << sourceInfo.file << ":" << sourceInfo.line << ":" << sourceInfo.pre + 1 << endl;
    // cout << "Used: struct " << name << " {" << code << "}" << endl;
    return res;
}

string solveCalledFunction(CalledFunction f, DefinedFunction cf) {
    string name = "";
    for (int i = f.name.size() - 1; i >= 0; i--)
        if (isalnum(f.name[i]) || f.name[i] == '_') name += f.name[i];
        else break;
    reverse(name.begin(), name.end());
    if (!userDefinedFunction.count(name)) {
        string res = f.name;
        if (f.templates.size()) { 
            res += "<";
            for (int i = 0; i < f.templates.size(); i++) res += 
                f.templates[i].value + 
                (i == f.templates.size() - 1 ? "" : ", ");
            res += ">";
        }
        res += "(";
        for (int i = 0; i < f.params.size(); i++) res += 
            f.params[i].value + 
            (i == f.params.size() - 1 ? "" : ", ");
        res += ")";
        return res;
    } else {
        string res = f.name;
        if (f.templates.size()) { 
            res += "<";
            for (int i = 0; i < f.templates.size(); i++) res += 
                f.templates[i].value + 
                (i == f.templates.size() - 1 ? "" : ", ");
            res += ">";
        }
        res += "(";
        f.params.insert(f.params.begin(), { "", "", "\"" + f.sourceInfo.file + "\"" });
        f.params.insert(f.params.begin(), { "", "", "" + to_string(f.sourceInfo.pre + 1) + "" });
        f.params.insert(f.params.begin(), { "", "", "" + to_string(f.sourceInfo.line) + "" });
        f.params.insert(f.params.begin(), { "", "", "\"" + cf.name + "\"" });
        f.params.insert(f.params.begin(), { "", "", "\"" + [&](){
            string res = "";
            for (int i = 0; i < cf.params.size(); i++) res += 
                cf.params[i].type +
                (i == cf.params.size() - 1 ? "" : ", ");
            return res;
        }() + "\"" });
        for (int i = 0; i < f.params.size(); i++) res += 
            f.params[i].value + 
            (i == f.params.size() - 1 ? "" : ", ");
        res += ")";
        return res;
    }
}

string solveIf(string condition, string body, SourceInfo sourceInfo, DefinedFunction cf) {
    string res = "if(" + condition + "){" + body + "}";
    if (cf.type == "SonolusApi") {
        res = "{"
            "createNodeContainer(\"\", \"\", 0, 0, \"\", false);" + 
            body + 
            "FuncNode trueNode = mergeNodeContainer(\"\", \"\", 0, 0, \"\");" 
            "SonolusRun(\"\", \"\", 0, 0, \"\", If(\"\", \"\", 0, 0, \"\", " + condition + ", trueNode, 0));"
        "}";
    }
    // cout << sourceInfo.file << ":" << sourceInfo.line << ":" << sourceInfo.pre + 1 << endl;
    // cout << "Used: if (" << condition << ") {" << body << "}" << endl;
    return res;
}

string solveIfElse(string condition, string trueBody, string falseBody, SourceInfo sourceInfo, DefinedFunction cf) {
    string res = "if(" + condition + "){" + trueBody + "}else{" + falseBody + "}";
    // cout << sourceInfo.file << ":" << sourceInfo.line << ":" << sourceInfo.pre + 1 << endl;
    // cout << "Used: else {" << body << "}" << endl;
    if (cf.type == "SonolusApi") {
        res = "{"
            "createNodeContainer(\"\", \"\", 0, 0, \"\", false); {" + 
            trueBody +
            "} FuncNode trueNode = mergeNodeContainer(\"\", \"\", 0, 0, \"\");" 
            "createNodeContainer(\"\", \"\", 0, 0, \"\", false); {" + 
            falseBody +
            "} FuncNode falseNode = mergeNodeContainer(\"\", \"\", 0, 0, \"\");" 
            "SonolusRun(\"\", \"\", 0, 0, \"\", If(\"\", \"\", 0, 0, \"\", " + condition + ", trueNode, falseNode));"
        "}";
    }
    return res;
}

string solveFor(string start, string end, string step, string body, SourceInfo sourceInfo, DefinedFunction cf) {
    string res = "for(" + start + ";" + end + ";" + step + "){" + body + "}";
    if (
        cf.type == "SonolusApi" && 
        start.find("CppLoop") == string::npos && 
        end.find("CppLoop") == string::npos && 
        step.find("CppLoop") == string::npos
    ) {
        string v = body; int pt = 0;
        while (v.find("break", pt) != string::npos) {
            int l = v.find("break", pt);
            int r = l; while (v[r] != ';') r++;
            string newst = "Break(\"\", \"\", 0, 0, \"\", blockCounter.top() - ForBlockCount, 0);";
            v = v.replace(l, r - l + 1, newst);
            pt = l + newst.size();
        }
        pt = 0;
        while (v.find("continue", pt) != string::npos) {
            int l = v.find("continue", pt);
            int r = l; while (v[r] != ';') r++;
            string newst = "{" + step + ";Break(\"\", \"\", 0, 0, \"\", blockCounter.top() - ForBlockCount - 1, 0);}";
            v = v.replace(l, r - l + 1, newst);
            pt = l + newst.size();
        }
        res = "{"
            "int ForBlockCount = blockCounter.top();"
            "createNodeContainer(\"\", \"\", 0, 0, \"\", false);" +
            start + ";"
            "createNodeContainer(\"\", \"\", 0, 0, \"\", false);" +
            v +
            step + ";"
            "SonolusRun(\"\", \"\", 0, 0, \"\", While(\"\", \"\", 0, 0, \"\", " + end + ", mergeNodeContainer(\"\", \"\", 0, 0, \"\")));"
            "SonolusRun(\"\", \"\", 0, 0, \"\", mergeNodeContainer(\"\", \"\", 0, 0, \"\"));"
        "}";
    }
    // cout << sourceInfo.file << ":" << sourceInfo.line << ":" << sourceInfo.pre + 1 << endl;
    // cout << "Used: for (" << start << "; " << end << "; " << step << ") {" << "}" << endl;
    // if (cf.name != "") {
    //     cout << "In: ";
    //     if (cf.templates.size()) {
    //         cout << "template<";
    //         for (int i = 0; i < cf.templates.size(); i++) 
    //             cout << cf.templates[i].type << " " << cf.templates[i].name << (i == cf.templates.size() - 1 ? "" : ",");
    //         cout << ">";
    //     }
    //     cout << cf.type << " " << cf.name << "(";
    //     for (int i = 0; i < cf.params.size(); i++) 
    //         cout << cf.params[i].type << " " << cf.params[i].name << (i == cf.params.size() - 1 ? "" : ",");
    //     cout << "){}" << endl;
    // }
    return res;
}

string solveWhile(string condition, string body, SourceInfo sourceInfo, DefinedFunction cf) {
    string res = "while(" + condition + "){" + body + "}";
    if (cf.type == "SonolusApi" && condition.find("CppLoop") == string::npos) {
        string v = body; int pt = 0;
        while (v.find("break", pt) != string::npos) {
            int l = v.find("break", pt);
            int r = l; while (v[r] != ';') r++;
            string newst = "Break(\"\", \"\", 0, 0, \"\", blockCounter.top() - ForBlockCount, 0);";
            v = v.replace(l, r - l + 1, newst);
            pt = l + newst.size();
        }
        pt = 0;
        while (v.find("continue", pt) != string::npos) {
            int l = v.find("continue", pt);
            int r = l; while (v[r] != ';') r++;
            string newst = "Break(\"\", \"\", 0, 0, \"\", blockCounter.top() - ForBlockCount - 1, 0);";
            v = v.replace(l, r - l + 1, newst);
            pt = l + newst.size();
        }
        res = "{"
            "int ForBlockCount = blockCounter.top();"
            "createNodeContainer(\"\", \"\", 0, 0, \"\", false);"
            "createNodeContainer(\"\", \"\", 0, 0, \"\", false);" +
            v +
            "SonolusRun(\"\", \"\", 0, 0, \"\", While(\"\", \"\", 0, 0, \"\", " + condition + ", mergeNodeContainer(\"\", \"\", 0, 0, \"\")));"
            "SonolusRun(\"\", \"\", 0, 0, \"\", mergeNodeContainer(\"\", \"\", 0, 0, \"\"));"
        "}";
    }
    // cout << sourceInfo.file << ":" << sourceInfo.line << ":" << sourceInfo.pre + 1 << endl;
    // cout << "Used: while(" << condition << "){" << "}" << endl;
    return res;
}

string solveSwitch(string var, vector<pair<string, string> > body, SourceInfo sourceInfo, DefinedFunction cf) {
    string res = "switch(" + var + "){";
    for (int i = 0; i < body.size(); i++) {
        if (body[i].first == "") res += "default: {";
        else res += "case " + body[i].first + ": {";
        res += body[i].second + "};";
    } res += "}";
    if (cf.type == "SonolusApi") {
        for (int i = int(body.size()) - 2; i >= 0; i--) body[i].second += body[i + 1].second;
        for (int i = 0; i < body.size(); i++) {
            string v = body[i].second; int pt = 0;
            while (v.find("break", pt) != string::npos) {
                int l = v.find("break", pt);
                int r = l; while (v[r] != ';') r++;
                string newst = "Break(\"\", \"\", 0, 0, \"\", blockCounter.top() - SwitchBlockCount, 0);";
                v = v.replace(l, r - l + 1, newst);
                pt = l + newst.size();
            }
            body[i].second = v;
        }
        res = "{"
            "int SwitchBlockCount = blockCounter.top();"
            "createNodeContainer(\"\", \"\", 0, 0, \"\", false);";
        for (int i = 0; i < body.size(); i++)
            res += 
                "createNodeContainer(\"\", \"\", 0, 0, \"\", false);" +
                body[i].second +
                "FuncNode node" + to_string(i) + " = mergeNodeContainer(\"\", \"\", 0, 0, \"\");";
        bool hasDefault = false;
        for (int i = 0; i < body.size(); i++) hasDefault |= body[i].first == "";
        res += "SonolusRun(\"\", \"\", 0, 0, \"\", Switch" + string(hasDefault ? "WithDefault" : "") + "(\"\", \"\", 0, 0, \"\", " + var + ", {";
        for (int i = 0; i < body.size(); i++) if (body[i].first != "") 
            res += "{" + body[i].first + ", node" + to_string(i) + " }, ";
        res += "}" + string(hasDefault ? ", " : "");
        for (int i = 0; i < body.size(); i++) if (body[i].first == "") 
            res += "node" + to_string(i);
        res += "));";
        res += 
            "SonolusRun(\"\", \"\", 0, 0, \"\", mergeNodeContainer(\"\", \"\", 0, 0, \"\"));"
        "}";
    }
    // cout << sourceInfo.file << ":" << sourceInfo.line << ":" << sourceInfo.pre + 1 << endl;
    // cout << "Used: " << res << endl;
    return res;
}

bool isInFunction = false;
void solvePreDefinedFunction(DefinedFunction f) {
    bool shouldBlock = f.name == "main" || 
        (f.params.size() && f.params[0].type == "string" && f.params[0].name == "callFromFunc") ||
        f.type == "Constructor" || f.type == "Destructor" || f.type == "operator" ||
        getWord(f.name, CppIdentifier) == Word({CppIdentifier, "operator"}) ||
        getWord(f.type, CppIdentifier) == Word({CppIdentifier, "operator"}) ||
        ss.back().back() == Word({ CppIdentifier, "Blocked" });
    if (!shouldBlock && needBlockedFunction.count(f.name))
        output(f.sourceInfo, "warning", "defining a function with the same name as a library function is not recommended.");
    if (shouldBlock) ;
    else {
        if (isInFunction) {
            output(f.sourceInfo, "error", "a function-definition is not allowed here.");
        }
        userDefinedFunction.insert(f.name);
        isInFunction = true;
    }
}

string solveDefinedFunction(DefinedFunction f) {
    string res = "";
    if (f.name != "main") {
        res += "\n// Function Define: " + f.type + " " + f.name + "(";
        for (int i = 0; i < f.params.size(); i++) res += f.params[i].type + (i == f.params.size() - 1 ? "" : ", ");
        res += ") in " + f.sourceInfo.file + ":" + to_string(f.sourceInfo.line) + "\n";
    }
    if (f.templates.size()) {
        res += "template<";
        for (int i = 0; i < f.templates.size(); i++) res += 
            trim(f.templates[i].type + " " + f.templates[i].name) + 
            (i == f.templates.size() - 1 ? "" : ", ");
        res += ">";
    } 
    bool shouldBlock = f.name == "main" || 
        (f.params.size() && f.params[0].type == "string" && f.params[0].name == "callFromFunc") ||
        f.type == "Constructor" || f.type == "Destructor" || f.type == "operator" ||
        getWord(f.name, CppIdentifier) == Word({CppIdentifier, "operator"}) ||
        getWord(f.type, CppIdentifier) == Word({CppIdentifier, "operator"}) ||
        ss.back().back() == Word({ CppIdentifier, "Blocked" });
    if (!shouldBlock) {
        f.params.insert(f.params.begin(), { "string", "callFromFile", "" });
        f.params.insert(f.params.begin(), { "int", "callFromColumn", "" });
        f.params.insert(f.params.begin(), { "int", "callFromLine", "" });
        f.params.insert(f.params.begin(), { "string", "callFromFunc", "" });
        f.params.insert(f.params.begin(), { "string", "callFromFuncParam", "" });
    }
    res += f.type + " " + f.name + "(";
    for (int i = 0; i < f.params.size(); i++) res += 
        trim(f.params[i].type + " " + f.params[i].name + (f.params[i].value != "" ? " = " + f.params[i].value : "")) + 
        (i == f.params.size() - 1 ? "" : ", ");
    res += ")";
    // cout << f.sourceInfo.file << ":" << f.sourceInfo.line << ":" << f.sourceInfo.pre + 1 << endl;
    // cout << "Defined: " << res << endl;
    if (shouldBlock) {
        if (f.type == "SonolusApi") {
            string v = f.sourceCode; int pt = 0;
            while (v.find("return", pt) != string::npos) {
                int l = v.find("return", pt);
                int r = l; while (v[r] != ';') r++;
                string returnCode = trim(v.substr(l + 6, r - l - 6));
                if (returnCode == "") returnCode = "0";
                string newst = "Break(\"\", \"\", 0, 0, \"\", blockCounter.top(), " + returnCode + ");";
                v = v.replace(l, r - l + 1, newst);
                pt = l + newst.size();
            }
            res += "{"
                "createNodeContainer(\"\", \"\", 0, 0, \"\");" +
                v + 
                "var code = mergeNodeContainer(\"\", \"\", 0, 0, \"\");"
                "return code;"
            "}";
        }
        else res += "{" + f.sourceCode + "}";
    } else {
        // res += string("{") + 
            // "cout << \"I'm " + f.name + " in " + f.sourceInfo.file + ":" + to_string(f.sourceInfo.line) + ", " + 
            // "I was called in \" << callFromFunc << \" in \" << callFromFile << \":\" << callFromLine << endl;" +
        //     f.sourceCode + 
        // "}";
        if (f.type == "SonolusApi") {
            string v = f.sourceCode; int pt = 0;
            while (v.find("return", pt) != string::npos) {
                int l = v.find("return", pt);
                int r = l; while (v[r] != ';') r++;
                string returnCode = trim(v.substr(l + 6, r - l - 6));
                if (returnCode == "") returnCode = "0";
                string newst = "Break(\"\", \"\", 0, 0, \"\", blockCounter.top(), " + returnCode + ");";
                v = v.replace(l, r - l + 1, newst);
                pt = l + newst.size();
            }
            res += "{"
                "int temporaryMemoryDelta = SonolusMemoryDelta[TemporaryMemoryId];"
                "callStacks.push_back({ callFromFile, callFromLine, callFromColumn, callFromFunc, callFromFuncParam });"
                "createNodeContainer(\"\", \"\", 0, 0, \"\");" +
                v + 
                "SonolusMemoryDelta[TemporaryMemoryId] = temporaryMemoryDelta;"
                "var code = mergeNodeContainer(\"\", \"\", 0, 0, \"\");"
                "callStacks.pop_back();"
                "return code;"
            "}";
        } else {
            string v = f.sourceCode; int pt = 0;
            while (v.find("return", pt) != string::npos) {
                int l = v.find("return", pt);
                int r = l; while (v[r] != ';') r++;
                string returnCode = trim(v.substr(l + 6, r - l - 6));
                string newst = "{ callStacks.pop_back(); return " + returnCode + "; }";
                v = v.replace(l, r - l + 1, newst);
                pt = l + newst.size();
            }
            res += "{" 
                "callStacks.push_back({ callFromFile, callFromLine, callFromColumn, callFromFunc, callFromFuncParam });" + 
                v + 
                "callStacks.pop_back();"
            "}";
        }
        isInFunction = false;
    }
    return res;
}