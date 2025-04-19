#include<bits/stdc++.h>
#ifndef __linux__
#include<direct.h>
#endif
using namespace std;

bool enableWarning = false;
string mode = "";

#include"file.h"
#include"string.h"
#include"algorithm.h"
#include"expand.h"
vector<vector<Word> > ss;
#include"solve.h"

/**
 * @param file 源文件地址
 * @param line 代码行数
 * @param pre 错误代码位置
 * @param type 错误类型
 * @param msg 错误信息
 * @param code 错误代码行
 * @param len 错误代码长度
 */
void output(string file, int line, int pre, string type, string msg, string code, int len) {
    if (type == "warning" && !enableWarning) return;
    cout << file << ":" << line << ":" << pre + 1 << ": " << type << ": " << msg << endl;
    cout << "  " << line << " | " << code << endl;
    if (len) cout << "  " << string(to_string(line).size(), ' ') << " | " << string(pre, ' ') << "^" << string(len - 1, '~') << endl; 
    else cout << "  " << string(to_string(line).size(), ' ') << " |" << endl;
    if (type.find("error") != string::npos) exit(1);
}
void output(SourceInfo source, string type, string msg) {
    output(source.file, source.line, source.pre, type, msg, source.lineCode, source.length);
}

/**
 * @brief 多头文件代码合并
 * @param src 入口文件路径
 * @return 合并后代码
 */
vector<SourceInfo> sources; // 每一行所对应的位置
string getCode(string src) {
    string source = readFile(src);
    string srcBase = getBasePath(src);
    auto commands = explode("\n", source);
    string result = ""; int dt = 0;
    for (int i = 0; i < commands.size(); i++) {
        string a = commands[i]; string original = a; a = ltrim(a);
        // 预处理指令处理
        if (a[0] == '#') {
            int pre = 0;
            pre++; a = a.erase(0, 1);
            pre += preLtrim(a); a = ltrim(a);
            int pre2 = pre;
            string type = getWord(a).code;
            pre += type.size(); a = a.substr(type.size());
            pre += preLtrim(a); a = ltrim(a);
            // 只处理 include
            if (type == "include") {
                // 系统头文件，直接忽略
                if (a[0] == '<') {
                    result += original + "\n";
                    sources.push_back({ src, commands[i], i + 1 - dt });
                } else if (a[0] == '\"' && a.find("\"", 1) != string::npos) {
                    string name = a.substr(1, a.find("\"", 1) - 1);
                    string newFile = srcBase + name;
                    if (!isFile(newFile)) {
                        int len = name.size() + 2;
                        output(src, i + 1, pre, "fatel error", newFile + ": No such file or directory", original, len);
                    } else result += getCode(newFile) + "\n";
                } else {
                    int len = a.size();
                    output(src, i + 1, pre, "error", "#include expects \"FILENAME\" or <FILENAME>", original, len);
                }
            } else {
                result += original + "\n";
                sources.push_back({ src, commands[i], i + 1 - dt });
            }
        } else {
            result += original + "\n";
            sources.push_back({ src, commands[i], i + 1 - dt });
        }
    } result.pop_back();
    // while (result.back() == '\n') result.pop_back();
    return result;
}
string mergedCode = "";

/**
 * @brief 获取源代码所在位置
 * @param 合并后的代码位置
 * @return 源代码所在位置
 */
SourceInfo getCodePlace(int wh) {
    int line = 0, pre = 0;
    for (int i = 0; i < wh; i++) 
        if (mergedCode[i] == '\n') line++, pre = 0;
        else pre++;
    SourceInfo res = sources[line];
    res.pre = pre;
    return res;
}

/**
 * @brief 整个代码去注释预处理
 * @param s 输入代码
 * @return 预处理后代码
 */
vector<pair<int, int> > comments;
string uncomment(string s) {
    string uncommented = ""; int commentType = 0;
    int commentIndex = 0;
    bool isString = false, isChar = false;
    for (int i = 0; i < s.size(); i++) {
        if (commentType == 0) {
            if (!isString && !isChar) {
                if (s[i] == '\"') isString = true;
                if (s[i] == '\'') isChar = true;
            } else {
                if (isString) {
                    if (s[i] == '\\') uncommented += s[i], i++;
                    else if (s[i] == '\"') isString = false;
                } else {
                    if (s[i] == '\\') uncommented += s[i], i++;
                    else if (s[i] == '\'') isChar = false;
                }
            }
        }
        if (i + 1 < s.size() && !isString && !isChar) {
            if (s[i] == '/' && s[i + 1] == '/' && commentType == 0) {
                commentType = 1, commentIndex = i, i++;
                continue;
            }
            if (s[i] == '/' && s[i + 1] == '*' && commentType == 0) {
                commentType = 2, commentIndex = i, i++;
                continue;
            } 
            if (s[i] == '*' && s[i + 1] == '/' && commentType == 2) {
                commentType = 0, comments.push_back({
                    commentIndex, i + 2
                }), commentIndex = 0, i++;
                continue;
            }
        }
        if (s[i] == '\n' && commentType == 1) comments.push_back({ commentIndex, i }), commentType = 0, commentIndex = 0;
        if (commentType == 0) uncommented += s[i];
    } if (commentType == 1) comments.push_back({ commentIndex, s.size() });
    if (commentType == 2) {
        SourceInfo info = getCodePlace(commentIndex);
        info.length = 2;
        output(info, "error", "unterminated comment");
    } sort(comments.begin(), comments.end());
    return uncommented;
}
string uncommentedCode = "";

/**
 * @brief 获取去注释预处理前代码位置
 * @param wh 去注释预处理后代码位置
 * @return 去注释预处理后代码位置
 */
int getCodePlace1(int wh) {
    int dt = 0;
    for (int i = 0; i < comments.size(); i++) 
        if (comments[i].first <= wh) wh += comments[i].second - comments[i].first;
    return wh + dt;
}

vector<Define> defines = { Define() };
map<string, int> definesMap;
vector<bool> used;
string rootCode = ""; int rootL = -1, rootR = -1, rootSize = -1;
string rootFile = ""; int rootLine = -1;
/**
 * @brief 给定一串代码，进行宏定义预处理
 * @param input 代码
 * @param output 预处理结果
 * @return 预处理结果信息 
 */
vector<ExpandRange> codeExpand(string input, string& output2, bool root = true) {
    int st = 0; string out = "";
    vector<ExpandRange> result;
    while(true) {
        int _min = 1e9, id = -1; pair<int, int> res = {-1, -1};
        for (auto it = definesMap.begin(); it != definesMap.end(); it++) {
            auto v = *it;
            if (v.second == 0 || used[v.second]) continue;
            if (blockedPreprocessor.count(v.first)) continue;
            int num = v.second;
            Define d = defines[v.second];
            pair<int, int> tmp = {-1, -1};
            if (d.isFunc) tmp = findCalledFunc(input, v.first, st);
            else tmp = findWord(input, v.first, st);
            if (tmp == pair<int, int>({-1, -1})) continue;
            if (tmp.first < _min) _min = tmp.first, id = v.second, res = tmp;
        }
        if (res == pair<int, int>({-1, -1})) break;
        out += input.substr(st, res.first - st);
        used[id] = true;
        Define d = defines[id];
        string sourceCode = input.substr(res.first, res.second - res.first);
        if (root) rootCode = input, rootL = res.first, rootR = res.second, rootSize = (d.isFunc ? d.funcName : d.source).size();
        if (!d.isFunc) {
            string out2 = "";
            sourceCode = d.target;
            codeExpand(sourceCode, out2, false);
            int l1 = out.size(); out += out2; int r1 = out.size();
            result.push_back({ res.first, res.second, d, l1, r1 });
        } else {
            // 获取参数
            vector<Parameter> params = getCalledParameters(sourceCode.substr(sourceCode.find('(')));
            if (params.size() > d.params.size() && (d.params.size() == 0 || d.params.back().value != "...")) {
                output(
                    d.sourceInfo.file, d.sourceInfo.line, 0,
                    "note", "macro \"" + d.funcName + "\" defined here",
                    d.sourceInfo.lineCode, 0
                );
                output(
                    rootFile, rootLine, rootL, 
                    "error", "macro \"" + d.funcName + "\" passed " + to_string(params.size()) + " arguments, but takes just " + to_string(d.params.size()),
                    rootCode, rootSize
                );
            }
            while (params.size() < d.params.size()) params.push_back({});
            if (params.size() > d.params.size()) {
                string last = "";
                for (int i = d.params.size() - 1; i < params.size(); i++)
                    last += params[i].value + (i == params.size() - 1 ? "" : ", ");
                params[d.params.size() - 1].value = last;
                params[d.params.size() - 1].sourceCode = last;
                params.resize(d.params.size());
            }
            sourceCode = d.target;
            // 参数替换
            struct range { int l, len; string to; }; vector<range> rs;
            for (int i = 0; i < d.params.size(); i++) {
                if (d.params[i].value == "...") d.params[i].value = "__VA_ARGS__";
                int st = 0, curr = findWord(sourceCode, d.params[i].value, st).first;
                while (curr != -1) {
                    int type = 0;
                    if (curr > 0 && sourceCode.substr(curr - 1, 1) == "#") type = 1;
                    if (type == 0) rs.push_back({ curr, int(d.params[i].value.size()), params[i].value });
                    if (type == 1) rs.push_back({ curr - 1, int(d.params[i].value.size()) + 1, "\"" + params[i].value + "\"" });
                    st = curr + d.params[i].value.size(); curr = findWord(sourceCode, d.params[i].value, st).first;
                }
            } sort(rs.begin(), rs.end(), [](range a, range b){ return a.l < b.l; });
            int dt = 0;
            for (int i = 0; i < rs.size(); i++) {
                sourceCode = sourceCode.replace(rs[i].l + dt, rs[i].len, rs[i].to);
                dt += rs[i].to.size() - rs[i].len;
            } sourceCode = str_replace(" ## ", "", sourceCode);
            string out2 = "";
            codeExpand(sourceCode, out2, false);
            int l1 = out.size(); out += out2; int r1 = out.size();
            result.push_back({ res.first, res.second, d, l1, r1 });
        }
        st = res.second;
        used[id] = false;
    } out += input.substr(st);
    output2 = out;
    return result;
}

/**
 * @brief 整个代码宏定义预处理
 * @param s 输入代码
 * @return 预处理后代码
 */
vector<ExpandRange> expands;
string preprocess(string s) {
    string source = "", preprocessed = "";
    auto commands = explode("\n", s);
    for (int i = 0; i < commands.size(); i++) {
        string a = commands[i]; string original = a; a = ltrim(a);
        // 预处理指令处理
        if (a[0] == '#') {
            source += commands[i] + "\n";
            preprocessed += commands[i] + "\n";
            int pre = 0;
            pre++; a = a.erase(0, 1);
            pre += preLtrim(a); a = ltrim(a);
            int pre2 = pre;
            string type = getWord(a).code;
            pre += type.size(); a = a.substr(type.size());
            pre += preLtrim(a); a = ltrim(a);
            if (!set<string>({"define", "undef", "ifdef", "ifndef", "if", "elif", "else", "endif", "pragma", "include"}).count(type)) {
                output(
                    sources[i].file, sources[i].line, pre2, 
                    "error", "unrecoginzed preprocess command \"" + type + "\"", 
                    original, type.size()
                );
            } else {
                if (type == "define" && definesMap["DISABLE_INTERPRETER"] == 0) {
                    Define d;
                    d.isFunc = false;
                    d.source = getWord(a).code;
                    d.sourceInfo = { sources[i].file, commands[i], sources[i].line };
                    if (definesMap[d.source]) {
                        // output(
                        //     sources[i].file, sources[i].line, pre,
                        //     "warning", "\"" + d.source + "\" redefined",
                        //     original, d.source.size()
                        // );
                    }
                    pre += d.source.size(); a = a.substr(d.source.size());
                    if (a[0] == '(') {
                        d.isFunc = true;
                        vector<Parameter> params = getCalledParameters(a);
                        int pre3 = 1;
                        // 函数参数查验
                        for (int j = 0; j < params.size(); j++) {
                            if (params[j].value == "..." && j != params.size() - 1) {
                                output(
                                    sources[i].file, sources[i].line, pre + pre3 + preLtrim(params[j].sourceCode), 
                                    "error", "expected ')' after \"" + params[j].value + "\"", 
                                    original, params[j].value.size()
                                );
                            }
                            if (params[j].value != "..." && getWord(params[j].value).code != params[j].value) {
                                output(
                                    sources[i].file, sources[i].line, pre + pre3 + preLtrim(params[j].sourceCode), 
                                    "error", "expected parameter name, found \"" + params[j].value + "\"", 
                                    original, params[j].value.size()
                                );
                            } pre3 += params[j].sourceCode.size() + 1;
                        }
                        pre += preGetCalledParamters(a); a = a.substr(preGetCalledParamters(a));
                        d.funcName = d.source; d.source = "";
                        d.params = params;
                    }
                    if (a[0] == ' ' || a == "") {
                        a = trim(a);
                        while (a.back() == '\\' && sources[i].line < commands.size()) 
                            a.pop_back(), a += trim(commands[++i]), source += commands[i] + "\n", preprocessed += commands[i] + "\n";
                        d.target = a;
                    } else {
                        output(
                            sources[i].file, sources[i].line, pre,
                            "error", string("expected primary-expression before '") + a[0] + string("' token"),
                            original, 1
                        );
                    }
                    d.target = str_replace("##", " ## ", d.target);
                    defines.push_back(d);
                    definesMap[d.isFunc ? d.funcName : d.source] = defines.size() - 1;
                } else if (type == "undef") {
                    string source = getWord(a).code;
                    if (source != trim(a))
                        output(
                            sources[i].file, sources[i].line, pre, 
                            "error", "macro names must be identifiers",
                            original, trim(a).size()
                        );
                    definesMap[source] = 0;
                }
            }
        } else {
            used.resize(defines.size());
            rootFile = sources[i].file;
            rootLine = sources[i].line;
            string output = "";
            auto x = codeExpand(commands[i], output);
            for (int j = 0; j < x.size(); j++) {
                auto v = x[j];
                // cout << int(source.size()) + v.l1 << " " << int(source.size()) + v.r1 << "|"
                //      << int(preprocessed.size()) + v.l2 << " " << int(preprocessed.size()) + v.r2 << endl;
                expands.push_back({ 
                    int(source.size()) + v.l1, int(source.size()) + v.r1, v.d,
                    int(preprocessed.size()) + v.l2, int(preprocessed.size()) + v.r2
                });
            } source += commands[i] + "\n"; preprocessed += output + "\n";
        }
    } preprocessed.pop_back();
    return preprocessed;
}
string preprocessedCode = "";

/**
 * @brief 获取宏定义预处理前代码位置
 * @param wh 宏定义预处理后代码位置
 * @return 宏定义预处理前代码位置
 */
int getCodePlace2(int wh) {
    int dt = 0;
    for (int i = 0; i < expands.size(); i++) {
        if (expands[i].l2 <= wh && wh <= expands[i].r2) return expands[i].l1;
        if (expands[i].r2 < wh) dt += (expands[i].r2 - expands[i].l2) - (expands[i].r1 - expands[i].l1);
    } return wh - dt;
}

/**
 * @brief 代码解析
 * @param s 输入代码
 * @return 解析后代码
 * @attention 如何获取代码原位置？getCodePlace2 -> getCodePlace1 -> getCodePlace
 */
DefinedFunction currentFunction = { {}, "", "", {}, "", {} };
string outputedCode = "";
string solve(string s) {
    int pt = 0;
    vector<char> type;
    ss.push_back({});
    bool isDebug = false;
    bool disableInterpreter = false;
    while (pt < s.size()) {
        while (s[pt] == ' ' || s[pt] == '\t' || s[pt] == '\r' || s[pt] == '\n' || s[pt] == '#') {
            if (s[pt] != '#') pt++;
            else {
                string res = ""; int wh = pt;
                while (s[pt] != '\n' || s[pt - 1] == '\\') res.push_back(s[pt]), pt++; pt++;
                ss.back().push_back({ CppSolvedSpecialSentence, "\n" + res + "\n", wh });
                int pt2 = 1;
                while (res[pt2] == ' ' || res[pt2] == '\t' || res[pt2] == '\r' || res[pt2] == '\n') pt2++;
                Word command = getWord(res, CppIdentifier, pt2);
                pt2 += command.code.size();
                if (command.code == "define") {
                    while (res[pt2] == ' ' || res[pt2] == '\t' || res[pt2] == '\r' || res[pt2] == '\n') pt2++;
                    Word name = getWord(res, CppIdentifier, pt2);
                    if (name.code == "DISABLE_INTERPRETER") disableInterpreter = true;
                } else if (command.code == "undef") {
                    while (res[pt2] == ' ' || res[pt2] == '\t' || res[pt2] == '\r' || res[pt2] == '\n') pt2++;
                    Word name = getWord(res, CppIdentifier, pt2);
                    if (name.code == "DISABLE_INTERPRETER") disableInterpreter = false;
                }
            }
        }
        Word w = getWord(s, CppIdentifier | CppNumber | CppCharacter | CppString | CppOperator, pt);
        if (disableInterpreter) {
            ss.back().push_back({ CppSolvedSpecialSentence, w.code, pt });
            pt += w.code.size();
            continue;
        }
        // if (pt > 1e4) isDebug = true;
        if (isDebug) {
            cout << "===========================================" << endl;
            cout << "{" << endl;
            for (int i = 0; i < ss.size(); i++) {
                cout << "\t{" << endl;
                for (int j = 0; j < ss[i].size(); j++) cout << "\t\t(" << ss[i][j].type << ", \"" << ss[i][j].code << "\")" << endl;
                cout << "\t}" << endl;
            }   
            cout << "}" << endl;
            cout << "===========================================" << endl;
            char x = getchar();
        }

        // 特殊函数处理函数
        function<string(string)> specialSolve = [&](string sentence){
            if (ss.back().size() == 0 || ss.back().back().type == CppSolvedSpecialSentence) return sentence; 
            int wh = ss.back().back().where;
            if (getWord(ss.back().back().code, CppIdentifier).code == "if") {
                string condition = ss.back().back().code;
                if (condition.find("(") == string::npos) {
                    SourceInfo info = getCodePlace(getCodePlace1(getCodePlace2(wh)));
                    info.length = 2;
                    output(info, "error", "expected '(' after 'if'");
                } 
                condition = condition.substr(condition.find("(") + 1);
                if (condition.find(")") == string::npos) {
                    SourceInfo info = getCodePlace(getCodePlace1(getCodePlace2(wh)));
                    info.length = 2;
                    output(info, "error", "expected ')' after '(' token after 'if'");
                } 
                condition = condition.substr(0, condition.rfind(")"));

                int tmppt = pt + w.code.size();
                while (s[tmppt] == ' ' || s[tmppt] == '\t' || s[tmppt] == '\r' || s[tmppt] == '\n' || s[tmppt] == '#') {
                    if (s[tmppt] != '#') tmppt++;
                    else { while (s[tmppt] != '\n' || s[tmppt - 1] == '\\') tmppt++; tmppt++; }
                }
                bool isElse = getWord(s, CppIdentifier, tmppt).code == "else";

                if (isElse) { return sentence + " "; }
                else {
                    string s = solveIf(condition, sentence, getCodePlace(getCodePlace1(getCodePlace2(wh))), currentFunction);
                    ss.back().pop_back();
                    return specialSolve(s);
                }
            }
            else if (getWord(ss.back().back().code, CppIdentifier).code == "else") {
                if (ss.back().size() < 3 || getWord(ss.back()[ss.back().size() - 3].code, CppIdentifier).code != "if") {
                    SourceInfo info = getCodePlace(getCodePlace1(getCodePlace2(wh)));
                    info.length = 4;
                    output(info, "error", "'else' without a previous 'if'");
                }
                string condition = ss.back()[ss.back().size() - 3].code;
                string trueSentence = trim(ss.back()[ss.back().size() - 2].code);
                condition = condition.substr(condition.find("(") + 1);
                condition = condition.substr(0, condition.rfind(")"));
                string s = solveIfElse(condition, trueSentence, sentence, getCodePlace(getCodePlace1(getCodePlace2(wh))), currentFunction);
                ss.back().pop_back();
                ss.back().pop_back();
                ss.back().pop_back();
                return specialSolve(s);
            }
            else if (getWord(ss.back().back().code, CppIdentifier).code == "for") {
                string condition = ss.back().back().code;
                if (condition.find("(") == string::npos) {
                    SourceInfo info = getCodePlace(getCodePlace1(getCodePlace2(wh)));
                    info.length = 3;
                    output(info, "error", "expected '(' after 'for'");
                } 
                condition = condition.substr(condition.find("(") + 1);
                if (condition.find(")") == string::npos) {
                    SourceInfo info = getCodePlace(getCodePlace1(getCodePlace2(wh)));
                    info.length = 3;
                    output(info, "error", "expected ')' after '(' token after 'for'");
                } 
                condition = condition.substr(0, condition.rfind(")"));
                auto tmp = explode(";", condition);
                if (tmp.size() < 3) {
                    SourceInfo info = getCodePlace(getCodePlace1(getCodePlace2(wh))); info.length = 3;
                    output(info, "error", "'for' loop must have 3 expressions");
                } 
                if (tmp.size() > 3) {
                    SourceInfo info = getCodePlace(getCodePlace1(getCodePlace2(wh))); info.length = 3;
                    output(info, "error", "'for' loop must have 3 expressions");
                }
                string s = solveFor(trim(tmp[0]), trim(tmp[1]), trim(tmp[2]), sentence, getCodePlace(getCodePlace1(getCodePlace2(wh))), currentFunction);
                ss.back().pop_back();
                return specialSolve(s);
            }
            else if (getWord(ss.back().back().code, CppIdentifier).code == "while") {
                string condition = ss.back().back().code;
                if (condition.find("(") == string::npos) {
                    SourceInfo info = getCodePlace(getCodePlace1(getCodePlace2(wh)));
                    info.length = 3;
                    output(info, "error", "expected '(' after 'for'");
                } 
                condition = condition.substr(condition.find("(") + 1);
                if (condition.find(")") == string::npos) {
                    SourceInfo info = getCodePlace(getCodePlace1(getCodePlace2(wh)));
                    info.length = 3;
                    output(info, "error", "expected ')' after '(' token after 'for'");
                }
                condition = condition.substr(0, condition.rfind(")"));
                string s = solveWhile(condition, sentence, getCodePlace(getCodePlace1(getCodePlace2(wh))), currentFunction);
                ss.back().pop_back();
                return specialSolve(s);
            }
            else return sentence;
            return sentence;
        };

        // 解析核心代码
        if (w.type == CppIdentifier) {
            if (
                ss.back().size() && ss.back().back().type == CppOperator && 
                (ss.back().back().code == "." || ss.back().back().code == "->" || ss.back().back().code == "::")
            ) {
                if (ss.back()[ss.back().size() - 2].type == CppIdentifier) {
                    auto tmp = ss.back().back().code;
                    ss.back().pop_back();
                    ss.back().back().code += tmp + w.code;
                } else ss.back().back().code += w.code, ss.back().back().type = CppIdentifier;
            } else if (set<string>({"if", "else", "for", "while", "switch"}).count(w.code)) {
                w.type = CppSentence;
                ss.back().push_back(w);
            } else if (w.code == "operator") {
                int pt2 = pt + w.code.size();
                while (s[pt2] == ' ' || s[pt2] == '\t' || s[pt2] == '\r' || s[pt2] == '\n' || s[pt2] == '#') {
                    if (s[pt2] != '#') pt2++;
                    else {
                        string res = ""; int wh = pt2;
                        while (s[pt2] != '\n' || s[pt2 - 1] == '\\') res.push_back(s[pt2]), pt2++; pt2++;
                        ss.back().push_back({ CppSolvedSpecialSentence, "\n" + res + "\n", wh });
                    }
                }
                Word w2 = getWord(s, CppOperator, pt2);
                if (w2.type == CppSpecial) ss.back().push_back(w);
                else {
                    w.code += " " + w2.code;
                    ss.back().push_back(w);
                    pt = pt2 + w2.code.size() - w.code.size();
                }
            } else ss.back().push_back(w);
        } else if (w.type == CppSpecial) {
            if (w.code == "{") ss.push_back({}), type.push_back(w.code[0]);
            else if (w.code == "(") ss.push_back({}), type.push_back(w.code[0]);
            else if (w.code == "[") ss.push_back({}), type.push_back(w.code[0]);
            else if (w.code == "}") {
                if (type.back() != '{') {
                    SourceInfo info = getCodePlace(getCodePlace1(getCodePlace2(pt)));
                    info.length = 1;
                    output(info, "error", "expected primary-expression before '}' token");
                }
                string sentence = "";
                for (int i = 0; i < ss.back().size(); i++) sentence += ss.back()[i].code + " ";
                sentence = trim(sentence);
                ss.pop_back(); type.pop_back();
                // 如果是函数定义
                if (
                    ss.back().size() >= 3 &&
                    ss.back().back().type == CppSentence && 
                    ss.back()[ss.back().size() - 2].type == CppIdentifier && 
                    ss.back()[ss.back().size() - 3].type == CppIdentifier
                ) {
                    DefinedFunction func;
                    func.params = {};
                    func.name = ss.back()[ss.back().size() - 2].code;
                    func.type = ss.back()[ss.back().size() - 3].code;
                    func.sourceCode = sentence;
                    func.templates = {};
                    bool hasTemplates = false;
                    if (
                        ss.back().size() >= 4 &&
                        ss.back()[ss.back().size() - 4].type == CppIdentifier && 
                        ss.back()[ss.back().size() - 4].code.substr(0, 8) == "template"
                    ) {
                        string templates = ss.back()[ss.back().size() - 4].code.substr(9);
                        templates = templates.substr(0, templates.size() - 1);
                        auto tmp = explode(",", templates);
                        for (int i = 0; i < tmp.size(); i++) {
                            if (trim(tmp[i]) == "") continue;
                            auto tmp2 = explode(" ", trim(tmp[i]));
                            string type = tmp2[0];
                            string name = "";
                            if (tmp2.size() > 1) name = tmp2[1];
                            func.templates.push_back({ type, name, "", "" });
                        } hasTemplates = true;
                    }
                    string params = ss.back().back().code.substr(1);
                    params = params.substr(0, params.size() - 1);
                    auto tmp = explode(",", params);
                    for (int i = 0; i < tmp.size(); i++) {
                        if (trim(tmp[i]) == "") continue;
                        string type = "", name = "", value = "";
                        auto tmp2 = explode("=", tmp[i]);
                        string tn = trim(tmp2[0]);
                        if (tmp2.size() > 1) value = trim(tmp2[1]);
                        auto tmp3 = explode(" ", tn);
                        if (tmp3.size() == 1) type = tmp3[0];
                        else {
                            name = tmp3.back();
                            for (int j = 0; j < tmp3.size() - 1; j++) type += tmp3[j] + " ";
                        }
                        func.params.push_back({ trim(type), trim(name), trim(value), "" });
                    }
                    ss.back().pop_back(); int wh = ss.back().back().where; ss.back().pop_back(); ss.back().pop_back();
                    if (hasTemplates) ss.back().pop_back();
                    func.sourceInfo = getCodePlace(getCodePlace1(getCodePlace2(wh)));
                    string s = "";
                    // 排除 lambda 表达式
                    if (getWord(func.name, CppSpecial) != Word({ CppSpecial, "[" }))
                        currentFunction = { {}, "", "", {}, "", {} }, s = solveDefinedFunction(func);
                    else s = [&](DefinedFunction f){
                        string res = "";
                        if (f.templates.size()) {
                            res += "template<";
                            for (int i = 0; i < f.templates.size(); i++) res += 
                                trim(f.templates[i].type + " " + f.templates[i].value) + 
                                (i == f.templates.size() - 1 ? "" : ", ");
                            res += ">";
                        }
                        res += f.type + " " + f.name + "(";
                        for (int i = 0; i < f.params.size(); i++) res += 
                            trim(f.params[i].type + " " + f.params[i].name + (f.params[i].value != "" ? " = " + f.params[i].value : "")) + 
                            (i == f.params.size() - 1 ? "" : ", ");
                        res += "){" + f.sourceCode + "}";
                        return res;
                    }(func);
                    ss.back().push_back({ CppSolvedSpecialSentence, s, wh });
                }
                else {
                    // 处理特殊函数
                    string res = specialSolve(sentence);
                    if (res != sentence) ss.back().push_back({ CppSolvedSpecialSentence, res, 0 });
                    // switch 处理
                    else if (
                        ss.back().size() &&
                        ss.back().back().type == CppSentence &&
                        getWord(ss.back().back().code, CppIdentifier) == Word({ CppIdentifier, "switch" })
                    ) {
                        string condition = ss.back().back().code;
                        string code = sentence;
                        int wh = ss.back().back().where;
                        if (condition.find("(") == string::npos) {
                            SourceInfo info = getCodePlace(getCodePlace1(getCodePlace2(wh)));
                            info.length = 2;
                            output(info, "error", "expected '(' after 'switch'");
                        } 
                        condition = condition.substr(condition.find("(") + 1);
                        if (condition.find(")") == string::npos) {
                            SourceInfo info = getCodePlace(getCodePlace1(getCodePlace2(wh)));
                            info.length = 2;
                            output(info, "error", "expected ')' after '(' token after 'switch'");
                        } 
                        condition = condition.substr(0, condition.rfind(")"));
                        vector<pair<string, string> > body;
                        string currCase = "", currSentence = "";
                        int pt2 = 0; bool isCase = false;
                        while (pt2 < code.size()) {
                            while (code[pt2] == ' ' || code[pt2] == '\t' || code[pt2] == '\r' || code[pt2] == '\n') pt2++;
                            auto w2 = getWord(code, CppIdentifier | CppNumber | CppCharacter | CppString | CppOperator, pt2);
                            if (w2 == Word({ CppIdentifier, "case" })) {
                                if (currSentence != "") body.push_back({ currCase, currSentence });
                                isCase = true;
                                currCase = ""; currSentence = "";
                            } else if (w2 == Word({ CppIdentifier, "default" })) {
                                if (currSentence != "") body.push_back({ currCase, currSentence });
                                isCase = true;
                                currCase = ""; currSentence = "";
                            } else if (w2 == Word({ CppOperator, ":" })) isCase = false;
                            else (isCase ? currCase : currSentence) += w2.code + " ";
                            pt2 += w2.code.size();
                        }
                        if (currSentence != "") body.push_back({ currCase, currSentence });
                        string s = solveSwitch(condition, body, getCodePlace(getCodePlace1(getCodePlace2(wh))), currentFunction);
                        ss.back().pop_back();
                        ss.back().push_back({ CppSolvedSpecialSentence, s, wh });
                    }
                    // 简单处理类定义或结构体定义
                    else if (
                        ss.back().size() >= 2 &&
                        ss.back().back().type == CppIdentifier && 
                        ss.back()[ss.back().size() - 2] == Word({ CppIdentifier, "class" })
                    ) {
                        string className = ss.back().back().code;
                        string code = sentence;
                        string s = solveClass(className, code, getCodePlace(getCodePlace1(getCodePlace2(ss.back().back().where))));
                        ss.back().pop_back(); ss.back().pop_back();
                        ss.back().push_back({ CppSentence, s });
                    }
                    else if (
                        ss.back().size() >= 2 &&
                        ss.back().back().type == CppIdentifier && 
                        ss.back()[ss.back().size() - 2] == Word({ CppIdentifier, "struct" })
                    ) {
                        string className = ss.back().back().code;
                        string code = sentence;
                        string s = solveStruct(className, code, getCodePlace(getCodePlace1(getCodePlace2(ss.back().back().where))));
                        ss.back().pop_back(); ss.back().pop_back();
                        ss.back().push_back({ CppSentence, s });
                    }
                    // 否则是初始化列表
                    else ss.back().push_back({ CppIdentifier, "{" + trim(sentence) + "}" });
                };
            }
            else if (w.code == ")") {
                if (type.back() != '(') {
                    SourceInfo info = getCodePlace(getCodePlace1(getCodePlace2(pt)));
                    info.length = 1;
                    output(info, "error", "expected primary-expression before ')' token");
                } type.pop_back();
                vector<string> params; string tmp = "";
                string sentence = "";
                for (int i = 0; i < ss.back().size(); i++) {
                    if (ss.back()[i].type == CppOperator && ss.back()[i].code == ",") params.push_back(trim(tmp)), tmp = "";
                    else tmp += ss.back()[i].code + " ";
                    sentence += ss.back()[i].code + " ";
                } if (trim(tmp) != "") params.push_back(trim(tmp)); ss.pop_back();
                // 如果是函数定义
                if (
                    ss.back().size() >= 2 && 
                    ss.back().back().type == CppIdentifier && 
                    ss.back()[ss.back().size() - 2].type == CppIdentifier &&
                    set<string>({ "return", "else" }).count(ss.back()[ss.back().size() - 2].code) == 0
                ) {
                    string param = "";
                    for (int i = 0; i < params.size(); i++) param += params[i] + (i == params.size() - 1 ? "" : ",");

                    // 排除掉 lambda 表达式
                    if (getWord(ss.back().back().code, CppSpecial ) != Word({ CppSpecial, "[" })) {
                        currentFunction.name = ss.back().back().code;
                        currentFunction.type = ss.back()[ss.back().size() - 2].code;
                        currentFunction.sourceInfo = getCodePlace(getCodePlace1(getCodePlace2(ss.back().back().where)));
                        currentFunction.params = {};
                        currentFunction.templates = {};

                        if (
                            ss.back().size() >= 3 &&
                            ss.back()[ss.back().size() - 3].type == CppIdentifier && 
                            ss.back()[ss.back().size() - 3].code.substr(0, 8) == "template"
                        ) {
                            string templates = ss.back()[ss.back().size() - 3].code.substr(9);
                            templates = templates.substr(0, templates.size() - 1);
                            auto tmp = explode(",", templates);
                            for (int i = 0; i < tmp.size(); i++) {
                                auto tmp2 = explode(" ", tmp[i]);
                                string type = tmp2[0];
                                string name = "";
                                if (tmp2.size() > 1) name = tmp2[1];
                                currentFunction.templates.push_back({ type, name, "", "" });
                            } 
                        }
                        auto tmp = explode(",", param);
                        for (int i = 0; i < tmp.size(); i++) {
                            string type = "", name = "", value = "";
                            auto tmp2 = explode("=", tmp[i]);
                            string tn = trim(tmp2[0]);
                            if (tmp2.size() > 1) value = trim(tmp2[1]);
                            auto tmp3 = explode(" ", tn);
                            type = trim(tmp3[0]);
                            for (int j = 1; j < tmp3.size(); j++) name += tmp3[j] + " ";
                            currentFunction.params.push_back({ type, name, value, "" });
                        }
                    }

                    DefinedFunction func;
                    func.params = {};
                    func.name = ss.back()[ss.back().size() - 1].code;
                    func.type = ss.back()[ss.back().size() - 2].code;
                    func.sourceCode = "";
                    func.templates = {};
                    bool hasTemplates = false;
                    Word name = ss.back()[ss.back().size() - 1], type = ss.back()[ss.back().size() - 2], templates;
                    if (
                        ss.back().size() >= 3 &&
                        ss.back()[ss.back().size() - 3].type == CppIdentifier && 
                        ss.back()[ss.back().size() - 3].code.substr(0, 8) == "template"
                    ) {
                        templates = ss.back()[ss.back().size() - 3];
                        string templates = ss.back()[ss.back().size() - 3].code.substr(9);
                        templates = templates.substr(0, templates.size() - 1);
                        auto tmp = explode(",", templates);
                        for (int i = 0; i < tmp.size(); i++) {
                            if (trim(tmp[i]) == "") continue;
                            auto tmp2 = explode(" ", trim(tmp[i]));
                            string type = tmp2[0];
                            string name = "";
                            if (tmp2.size() > 1) name = tmp2[1];
                            func.templates.push_back({ type, name, "", "" });
                        } hasTemplates = true;
                    }
                    for (int i = 0; i < params.size(); i++) {
                        if (trim(params[i]) == "") continue;
                        string type = "", name = "", value = "";
                        auto tmp2 = explode("=", params[i]);
                        string tn = trim(tmp2[0]);
                        if (tmp2.size() > 1) value = trim(tmp2[1]);
                        auto tmp3 = explode(" ", tn);
                        type = trim(tmp3[0]);
                        for (int j = 1; j < tmp3.size(); j++) name += tmp3[j] + " ";
                        func.params.push_back({ trim(type), trim(name), trim(value), "" });
                    }
                    string funcName = ss.back().back().code;
                    ss.back().pop_back(); ss.back().pop_back();
                    if (hasTemplates) ss.back().pop_back();
                    
                    // 排除掉 lambda 表达式
                    if (getWord(ss.back().back().code, CppSpecial ) != Word({ CppSpecial, "[" })) solvePreDefinedFunction(func);
                    if (hasTemplates) ss.back().push_back(templates);
                    ss.back().push_back(type); ss.back().push_back(name);
                    ss.back().push_back({ CppSentence, "(" + param + ")", 0 });
                }
                // 特殊函数处理 -> 扔函数那边处理
                else if (ss.back().size() && set<string>({"if", "for", "while", "switch"}).count(ss.back().back().code)) {
                    ss.back().back().code += "(" + trim(sentence) + ")";
                    ss.back().back().type = CppSentence;
                }
                // 如果是表达式
                else if (ss.back().size() == 0 || ss.back().back().type != CppIdentifier) {
                    string sentence = "(";
                    for (int i = 0; i < params.size(); i++) sentence += params[i] + ",";
                    if (params.size()) sentence.pop_back();
                    sentence += ")";
                    ss.back().push_back({ CppIdentifier, sentence, 0 });
                }
                // 否则是函数调用
                else {
                    CalledFunction func;
                    func.templates = {};
                    int wh = ss.back().back().where;
                    // if (ss.back().back().code.substr(0, 3) == "set") cout << ss.back().back().code << endl;
                    func.name = ss.back().back().code;
                    func.params = {};
                    func.sourceInfo = getCodePlace(getCodePlace1(getCodePlace2(ss.back().back().where)));
                    if (func.name.back() == '>') {
                        string templates = func.name.substr(func.name.find("<") + 1);
                        templates = templates.substr(0, templates.size() - 1);
                        auto tmp = explode(",", templates);
                        func.name = func.name.substr(0, func.name.find("<"));
                        for (int i = 0; i < tmp.size(); i++) if (trim(tmp[i]) != "") func.templates.push_back({ "", "", trim(tmp[i]), "" });
                    } ss.back().pop_back();
                    for (int i = 0; i < params.size(); i++) func.params.push_back({ "", "", params[i], "" });
                    string res = "";
                    res = solveCalledFunction(func, currentFunction);
                    ss.back().push_back({ CppIdentifier, res, wh });
                }
            }
            else if (w.code == "]") {
                if (type.back() != '[') {
                    SourceInfo info = getCodePlace(getCodePlace1(getCodePlace2(pt)));
                    info.length = 1;
                    output(info, "error", "expected primary-expression before ']' token");
                } type.pop_back();
                string sentence = "[";
                for (int i = 0; i < ss.back().size(); i++) sentence += ss.back()[i].code + " ";
                ss.pop_back();
                if (ss.back().back().type == CppIdentifier) ss.back().back().code += trim(sentence) + "]";
                else ss.back().push_back({ CppIdentifier, "", 0 }), ss.back().push_back({ CppIdentifier, trim(sentence) + "]", 0 });
            }
            else if (w.code == ";") {
                string sentence = ""; vector<string> tmp;
                while (ss.back().size() && set<int>({CppSentence, CppSolvedSpecialSentence}).count(ss.back().back().type) == 0) 
                    tmp.push_back(ss.back().back().code), ss.back().pop_back();
                reverse(tmp.begin(), tmp.end());
                for (int i = 0; i < tmp.size(); i++) sentence += tmp[i] + " ";
                // ss.back().push_back({ CppSentence, trim(sentence) + ";", 0 });
                string res = specialSolve(sentence + ";");
                ss.back().push_back({ CppSolvedSpecialSentence, res, 0 });
            } 
            else ss.back().push_back(w);
        } else if (w.type == CppOperator) {
            if (w.code == "." && ss.back().size() >= 2 && ss.back().back().code == "." && ss.back()[ss.back().size() - 2].code == ".") {
                ss.back().pop_back();
                ss.back().back().code += "..";
                ss.back().back().type = CppIdentifier;
                if (ss.back().size() >= 2 && ss.back()[ss.back().size() - 2].type == CppIdentifier) {
                    ss.back().pop_back();
                    ss.back().back().code += "...";
                }
            }
            else if (w.code == ">") {
                vector<Word> tmp;
                while (ss.back().size() && ss.back().back() != Word({ CppOperator, "<" })) tmp.push_back(ss.back().back()), ss.back().pop_back();
                reverse(tmp.begin(), tmp.end());
                auto recover = [&](){
                    for (int i = 0; i < tmp.size(); i++) ss.back().push_back(tmp[i]);
                    ss.back().push_back(w);
                };
                if (ss.back().size() == 0) recover();
                else {
                    bool is1 = true, is2 = true;
                    if (tmp.size() % 2 == 0) is1 = false;
                    if (tmp.size() % 3 != 2) is2 = false;
                    for (int i = 0; i < tmp.size(); i++) {
                        if (i % 2 == 1 && tmp[i] != Word({ CppOperator, "," })) is1 = false;
                        if (i % 2 == 0 && set<int>({ CppIdentifier, CppNumber, CppString, CppCharacter }).count(tmp[i].type) == 0) is1 = false;
                    }
                    for (int i = 0; i < tmp.size(); i++) {
                        if (i % 3 == 2 && tmp[i] != Word({ CppOperator, "," })) is2 = false;
                        if (i % 3 != 2 && tmp[i].type != CppIdentifier) is2 = false;
                    }
                    if (!is1 && !is2) recover();
                    else {
                        ss.back().pop_back();
                        string sentence = "";
                        for (int i = 0; i < tmp.size(); i++) {
                            if (tmp[i].code == ",") sentence.pop_back();
                            sentence += tmp[i].code + " ";
                        } ss.back().back().code += "<" + trim(sentence) + ">";
                    }
                }
            } else ss.back().push_back(w);
        } else ss.back().push_back(w);

        pt += w.code.size();
    }
    string res = "";
    for (int i = 0; i < ss.size(); i++) {
        for (int j = 0; j < ss[i].size(); j++) {
            res += ss[i][j].code + " ";
        }
    } return res;
}

/**
 * @brief 代码压缩
 * @param s 输入代码
 * @return 压缩后代码
 */
string compress(string s) {
    auto l = explode("\n", s);
    string output = "";
    for (int i = 0; i < l.size(); i++) {
        string s = trim(l[i]);
        if (s == "") continue;
        if (s[0] == '#' || s.substr(0, 2) == "//") {
            output += s + "\n";
            continue;
        } else {
            string tmp = "";
            int pt = 0; int lastWordType = -1;
            while (pt < s.size()) {
                while (s[pt] == ' ' || s[pt] == '\t' || s[pt] == '\r' || s[pt] == '\n') pt++;
                Word w = getWord(s, CppIdentifier | CppNumber | CppCharacter | CppString | CppOperator, pt);
                if (
                    w.type != CppOperator && 
                    w.type != CppSpecial && 
                    lastWordType == CppIdentifier
                ) tmp += " " + w.code;
                else tmp += w.code;
                lastWordType = w.type; pt += w.code.size();
            } output += tmp + "\n";
        }
    } output.pop_back();
    return output;
}

int main(int argc, char** argv) {
    if (argc < 2) {
        cout << "Sonolus Engine C++ Compiler v1.0.0" << endl;
        cout << endl;
        cout << "Usage: " << argv[0] << " <main.cpp> [output] [-w]" << endl;
        return 1;
    }
    string entry = argv[1];
    string output = argc > 2 ? argv[2] : ".sonolus";
    enableWarning = !(argc > 3);
    if (output.back() != '/' && output.back() != '\\') output += "/";
    #ifdef __linux__
    mkdir(output.c_str(), 0777);
    #else
    _mkdir(output.c_str());
    #endif
    ofstream fout; fout.open(output + "main.cpp");
    mergedCode = getCode(entry);
    // fout << mergedCode;
    time_t st = clock();
    uncommentedCode = uncomment(mergedCode);
    cout << "Uncommenting finished! Used " << 1.0 * (clock() - st) / CLOCKS_PER_SEC << "s" << endl;
    // fout << uncommentedCode;
    st = clock();
    preprocessedCode = preprocess(uncommentedCode);
    cout << "Preprocessing finished! Used " << 1.0 * (clock() - st) / CLOCKS_PER_SEC << "s" << endl;
    // fout << preprocessedCode;
    st = clock();
    outputedCode = solve(preprocessedCode);
    cout << "Solving finished! Used " << 1.0 * (clock() - st) / CLOCKS_PER_SEC << "s" << endl;
    fout << "#define COMPILE_RUNTIME" << endl;
    st = clock();
    fout << compress(outputedCode);
    cout << "Compressing finished! Used " << 1.0 * (clock() - st) / CLOCKS_PER_SEC << "s" << endl;
}
