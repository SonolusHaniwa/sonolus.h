string readFile(string path) {
    ifstream fin;
    fin.open(path);
    if (!fin) return "";
    fin.seekg(0, ios::end);
    int len = fin.tellg();
    fin.seekg(0, ios::beg);
    char *ch = new char[len];
    fin.read(ch, len);
    string s = string(ch, len);
    delete[] ch;
    fin.close();
    return s;
}

void writeFile(string path, string content) {
    ofstream fout;
    fout.open(path);
    fout.write(content.c_str(), content.size());
    fout.close();
}

bool isFile(string path) {
    ifstream fin;
    fin.open(path);
    return bool(fin);
}

#ifdef __linux__
#include<sys/stat.h>
#else
#endif
void forceMkdir(string path, int mode) {
    int st = 0;
    while(true) {
        int nxt = min(
            path.find("/", st) == string::npos ? 1e9 : path.find("/", st),
            path.find("\\", st) == string::npos ? 1e9 : path.find("\\", st)
        );
        if (nxt == 1e9) break;
        string name = path.substr(0, nxt);
        #ifdef __linux__
        mkdir(name.c_str(), mode);
        #else
        _mkdir(name.c_str());
        #endif
        st = nxt + 1;
    }
}

string getBasePath(string path) {
    if (path.find("/") == string::npos && path.find("\\") == string::npos) return "./";
    return path.substr(0, max(
        path.rfind("/") == string::npos ? -1 : int(path.rfind("/")),
        path.rfind("\\") == string::npos ? -1 : int(path.rfind("\\"))
    ) + 1);
}
