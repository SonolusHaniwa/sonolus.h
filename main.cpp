#include<bits/stdc++.h>
#include"sonolus.h"
using namespace std;
string readFile(string path) {
    ifstream fin(path.c_str());
    fin.seekg(0, ios::end);
    int len = fin.tellg();
    if (len == -1) return "";
    fin.seekg(0, ios::beg);
    char* ch = new char[len];
    fin.read(ch, len);
    string buffer;
    for (int i = 0; i < len; i++) buffer.push_back(ch[i]);
    delete[] ch;
    return buffer;
}

const string dist = "./dist";

int main() {
    Json::Value data; json_decode(readFile("./EngineData.json"), data);
    Json::Value configuration; json_decode(readFile("./EngineConfiguration.json"), configuration);
    EngineData engineData; engineData.scripts.push_back(EngineDataScript());
    EngineConfiguration engineConfiguration = EngineConfiguration(configuration);
    auto &tmp = engineData.scripts[0].initialize;
    tmp = ArchetypeLife[120].get(1);

    buffer resData, resConfiguration;
    build(engineConfiguration, engineData, resConfiguration, resData);
    ofstream fout((dist + "/EngineConfiguration"));
    for (int i = 0; i < resConfiguration.size(); i++) fout << resConfiguration.v[i];
    fout.close(); fout.open((dist + "/EngineData"));
    for (int i = 0; i < resData.size(); i++) fout << resData.v[i];
}