#include<bits/stdc++.h>
#include"sonolus.h"
using namespace std;

const string dist = "./dist";
#include"engine/engine.cpp"

int main(int argc, char** argv) {
    engineConfiguration.ui = configurationUI;
#ifdef play
    buffer data, configuration;
    build<
        // Replace with your archetypes here
        Archetype
    >(configuration, data);
    ofstream fout((dist + "/EngineConfiguration"));
    for (int i = 0; i < configuration.size(); i++) fout << configuration.v[i];
    fout.close(); fout.open((dist + "/EngineData"));
    for (int i = 0; i < data.size(); i++) fout << data.v[i];
#elif tutorial
    buffer data, configuration;
    build(configuration, data);
    ofstream fout((dist + "/EngineConfiguration"));
    for (int i = 0; i < configuration.size(); i++) fout << configuration.v[i];
    fout.close(); fout.open((dist + "/EngineTutorialData"));
    for (int i = 0; i < data.size(); i++) fout << data.v[i];
#endif
}