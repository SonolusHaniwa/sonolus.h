#include<bits/stdc++.h>
#include"sonolus.h"
using namespace std;
const string dist = "./dist";

EngineConfigurationUI configurationUI;

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
    // ofstream fout((dist + "/EngineData"));
    for (int i = 0; i < data.size(); i++) fout << data.v[i];
#elif tutorial
    buffer data, configuration;
    build(configuration, data);
    ofstream fout((dist + "/EngineConfiguration"));
    for (int i = 0; i < configuration.size(); i++) fout << configuration.v[i];
    fout.close(); fout.open((dist + "/EngineTutorialData"));
    for (int i = 0; i < data.size(); i++) fout << data.v[i];
#elif preview
    buffer data, configuration;
    build<
        // Replace with your archetypes here
        Archetype
    >(configuration, data);
    ofstream fout((dist + "/EngineConfiguration"));
    for (int i = 0; i < configuration.size(); i++) fout << configuration.v[i];
    fout.close(); fout.open((dist + "/EnginePreviewData"));
    for (int i = 0; i < data.size(); i++) fout << data.v[i];
#elif watch
	buffer data, configuration;
	build<
		// Replace with your archetypes here
		Archetype
	>(configuration, data);
    ofstream fout((dist + "/EngineConfiguration"));
    for (int i = 0; i < configuration.size(); i++) fout << configuration.v[i];
    fout.close(); fout.open((dist + "/EngineWatchData"));
    for (int i = 0; i < data.size(); i++) fout << data.v[i];
#endif

	// 生成 Skin
	packSkin(dist + "/SkinTexture", dist + "/SkinData");
    // 生成 Effect
    packEffect(dist + "/EffectAudio", dist + "/EffectData");
}
