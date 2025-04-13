struct SourceInfo {
    string file = "";
    string lineCode = "";
    int line = 0;
    int pre = 0;
    int length = 0;
};
struct Parameter {
    string type = "";
    string name = "";
    string value = "";
    string sourceCode = ""; // 仅供部分代码使用
};
struct Define {
    bool isFunc = false;
    string source = "";
    string target = "";
    string funcName = "";
    vector<Parameter> params = {};
    SourceInfo sourceInfo;
};
struct DefinedFunction {
    vector<Parameter> templates = {};
    string type = "";
    string name = "";
    vector<Parameter> params = {};
    string sourceCode = "";
    SourceInfo sourceInfo;
};
struct CalledFunction {
    vector<Parameter> templates = {};
    string name = "";
    vector<Parameter> params = {};
    SourceInfo sourceInfo;
};
struct Class {
    vector<Parameter> templates = {};
    string name = "";
    vector<DefinedFunction> funcs = {};
    string sourceCode = "";
};
struct ExpandRange {
    int l1, r1; Define d;
    int l2, r2;
};
enum WordType {
    CppIdentifier = 1 << 0,
    CppNumber = 1 << 1,
    CppCharacter = 1 << 2,
    CppString = 1 << 3,
    CppOperator = 1 << 4,
    CppSpecial = 1 << 5,
    CppSentence = 1 << 6,
    CppSolvedSpecialSentence = 1 << 30
};
vector<string> cppOperators = {
    "&&", "||", "[]",
    "+=", "-=", "*=", "/=", "%=", "<<=", ">>=", "&=", "^=", "|=",
    "&", "|", "^", "~", ">>", "<<",
    "==", "!=", ">=", "<=", ">", "<", "=",
    "++", "--", "+", "->", "-", "*", "/", "%",
    "::", "?", ":", ",", ".", "&", "*", "!"
};
struct Word {
    WordType type;
    string code;
    int where = 0;
    bool operator == (Word a) {
        return type == a.type && code == a.code;
    }
    bool operator != (Word a) {
        return type != a.type || code != a.code;
    }
};

// 一定要注意第一个字符是 '(' !!!
int preGetCalledParamters(string s) {
    assert(s[0] == '(');
    int b = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '(') b++;
        if (s[i] == ')') b--;
        if (b == 0) return i + 1;
    } assert(false);
}
vector<Parameter> getCalledParameters(string s) {
    assert(s[0] == '(');
    vector<Parameter> res = {};
    string source = s.substr(0, preGetCalledParamters(s));
    source = source.substr(1, source.size() - 2);
    int b = 0; string curr = "";
    for (int i = 0; i < source.size(); i++) {
        if (source[i] == '(') b++;
        if (source[i] == ')') b--;
        if (source[i] == ',' && b == 0) {
            res.push_back({ "", "", trim(curr), curr });
            curr = "";
        } else curr.push_back(source[i]);
    } if (trim(curr).size()) res.push_back({ "", "", trim(curr), curr });
    return res;
}
vector<Parameter> getDefinedParameters(string s) {
    return {};
}
Word getWord(string &s, int accept = CppIdentifier, int pos = 0) {
    Word res; int tmp = pos;
    res.where = pos;
    // 读取关键字
    if (accept & CppIdentifier) {
        res.code = ""; pos = tmp;
        if (pos < s.size() && (isalpha(s[pos]) || s[pos] == '_')) {
            res.code.push_back(s[pos]); pos++;
            for (int i = pos; i < s.size(); i++) 
                if (isalnum(s[i]) || s[i] == '_') res.code.push_back(s[i]);
                else break;
            res.type = CppIdentifier;
            return res;
        }
    }
    // 读取数字
    if (accept & CppNumber) {
        res.code = ""; pos = tmp;
        if (pos < s.size() && isdigit(s[pos])) {
            res.code.push_back(s[pos]); pos++;
            for (int i = pos; i < s.size(); i++) 
                if (isalnum(s[i])) res.code.push_back(s[i]);
                else break;
            res.type = CppNumber;
            return res;
        }
    }
    // 读取字符
    if (accept & CppCharacter) {
        res.code = ""; pos = tmp;
        if (pos < s.size() && s[pos] == '\'') {
            res.code.push_back(s[pos]); pos++;
            for (int i = pos; i < s.size(); i++, pos++) 
                if (s[i] == '\\') res.code.push_back(s[i]), res.code.push_back(s[++i]), pos++;
                else if (s[i] != '\'') res.code.push_back(s[i]);
                else break;
            if (pos < s.size() && s[pos] == '\'') {
                res.code.push_back(s[pos]);
                res.type = CppCharacter;
                return res;
            }
        }
    }
    // 读取字符串
    if (accept & CppString) {
        res.code = ""; pos = tmp;
        if (pos < s.size() && s[pos] == '\"') {
            res.code.push_back(s[pos]); pos++;
            for (int i = pos; i < s.size(); i++, pos++) 
                if (s[i] == '\\') res.code.push_back(s[i]), res.code.push_back(s[++i]), pos++;
                else if (s[i] != '\"') res.code.push_back(s[i]);
                else break;
            if (pos < s.size() && s[pos] == '\"') {
                res.code.push_back(s[pos]);
                res.type = CppString;
                return res;
            }
        }
    }
    // 读取操作符
    if (accept & CppOperator) {
        for (int i = 0; i < cppOperators.size(); i++) {
            if (pos + cppOperators[i].size() <= s.size() && s.substr(pos, cppOperators[i].size()) == cppOperators[i]) {
                res.code = cppOperators[i];
                res.type = CppOperator;
                return res;
            }
        }
    }
    // 否则是特殊字符
    res.code = s[pos]; res.type = CppSpecial;
    return res;
}
int findRealWord(string s, string t, int pos) {
    char in = '\0';
    for (int i = pos; i + t.size() <= s.size(); i++) {
        if (s[i] == '"') {
            if (in == '\0') in = '\"';
            else if (in == '\"') in = '\0';
        }
        if (s[i] == '\'') {
            if (in == '\0') in = '\'';
            else if (in == '\'') in = '\0';
        }
        if (in != '\0') continue;
        if (s.substr(i, t.size()) == t) return i;
    }
    return string::npos;
}
pair<int, int> findWord(string s, string t, int pt = 0) {
    int st = pt, curr = findRealWord(s, t, st);
    while (curr != string::npos) {
        if (
            (curr - 1 < 0 || !isalnum(s[curr - 1]) && s[curr - 1] != '_') &&
            (curr + t.size() >= s.size() || !isalnum(s[curr + t.size()]) && s[curr + t.size()] != '_')
        ) return {curr, curr + t.size()};
        st = curr + t.size();
        curr = findRealWord(s, t, st);
    } return {-1, -1};
}
pair<int, int> findCalledFunc(string s, string t, int pt = 0) {
    int st = pt, curr = findWord(s, t, st).first;
    while (curr != -1) {
        int l = curr;
        int r = curr + t.size();
        while (s[r] == ' ') r++;
        if (s[r] != '(') {
            st = curr + t.size();
            curr = findWord(s, t, st).first;
            continue;
        } int b = 1;
        for (int i = r + 1; i < s.size(); i++) {
            if (s[i] == '(') b++;
            if (s[i] == ')') b--;
            if (b == 0) return {l, i + 1};
        } st = curr + t.size();
        curr = findWord(s, t, st).first;
    } return {-1, -1};
}