string ltrim(string s) {
    while (s.size() && (s.front() == ' ' || s.front() == '\t' || s.front() == '\r')) s = s.erase(0, 1);
    return s;
}
int preLtrim(string s) {
    int cnt = 0;
    while (s.size() && (s.front() == ' ' || s.front() == '\t' || s.front() == '\r')) s = s.erase(0, 1), cnt++;
    return cnt;
}
string rtrim(string s) {
    while (s.size() && (s.back() == ' ' || s.back() == '\t' || s.back() == '\r')) s.pop_back();
    return s;
}
int preRtrim(string s) {
    int cnt = 0;
    while (s.size() && (s.back() == ' ' || s.back() == '\t' || s.back() == '\r')) s.pop_back(), cnt++;
    return cnt;
}
string trim(string s) {
    return ltrim(rtrim(s));
}
vector<string> explode(string seperator, string source) {
	string src = source; vector<string> res;
	while (src.find(seperator) != string::npos) {
		int wh = src.find(seperator);
		res.push_back(src.substr(0, src.find(seperator)));
		src = src.substr(wh + string(seperator).size());
	} res.push_back(src);
	return res;
}
vector<string> explode(vector<string> seperators, string source) {
    vector<string> res = { source };
    for (int i = 0; i < seperators.size(); i++) {
        vector<string> tmp = {};
        for (int j = 0; j < res.size(); j++) {
            auto tmp2 = explode(seperators[i], res[j]);
            tmp.insert(tmp.end(), tmp2.begin(), tmp2.end());
        } res = tmp;
    } return res;
}
string str_replace(string from, string to, string source, bool supportTranfer = false) {
    string result = source;
	int st = 0, wh = result.find(from.c_str(), st);
	while (wh != string::npos) {
        if (supportTranfer && wh >= 1 && result[wh - 1] == '\\') {
            st = wh + 1;
            wh = result.find(from.c_str(), st);
            continue;
        } 
        result.replace(wh, from.size(), to.c_str());
		st = wh + to.size();
		wh = result.find(from.c_str(), st);
	} 
    return result;
}
string str_replace(vector<pair<string, string> > s, string source, bool supportTransfer = false) {
    string result = source;
    for (int i = 0; i < s.size(); i++) result + str_replace(s[i].first, s[i].second, result, supportTransfer);
    return result;
}