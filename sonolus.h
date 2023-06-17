#include<jsoncpp/json/json.h>
#include<openssl/ssl.h>

#include"modules/modules.h"

#include"items/EngineEnums.h"
#include"items/FuncNode.h"
#include"items/EngineConfiguration.h"
#include"items/EngineData.h"

#include"functions/functions.h"
#ifndef DISABLE_REDEFINE
#include"functions/redefine.h"
#endif
#ifndef DISABLE_JSPREFER
typedef FuncNode var;
typedef FuncNode let;
#endif

#include"blocks/Blocks.h"

map<EngineDataNode, int> hashMap;

int buildScript(FuncNode script, EngineData& data) {
    EngineDataNode res;
    if (script.isValue == true) res = EngineDataValueNode(script.value);
    else {
        vector<double> args;
        for (int i = 0; i < script.args.size(); i++) args.push_back(buildScript(script.args[i], data));
        res = EngineDataFunctionNode(script.func, args);
    } if (hashMap.find(res) != hashMap.end()) return hashMap[res];
    hashMap[res] = data.nodes.size(); data.nodes.push_back(res);
    return hashMap[res];
}

bool isInitial(FuncNode a) {
    return a.isValue && a.value == -1;
}

void build(EngineConfiguration configuration, EngineData data, buffer& configurationBuffer, buffer& dataBuffer) {
    configurationBuffer = compress_gzip(json_encode(configuration.toJsonObject()), 9);
    hashMap.clear();
    for (int i = 0; i < data.archetypes.size(); i++) {
        auto &e = data.archetypes[i];
        if (!isInitial(e.initialize.script)) e.initialize = EngineDataArchetypeCallback(buildScript(e.initialize.script, data));
        if (!isInitial(e.spawnOrder.script)) e.spawnOrder = EngineDataArchetypeCallback(buildScript(e.spawnOrder.script, data));
        if (!isInitial(e.shouldSpawn.script)) e.shouldSpawn = EngineDataArchetypeCallback(buildScript(e.shouldSpawn.script, data));
        if (!isInitial(e.preprocess.script)) e.preprocess = EngineDataArchetypeCallback(buildScript(e.preprocess.script, data));
        if (!isInitial(e.updateSequential.script)) e.updateSequential = EngineDataArchetypeCallback(buildScript(e.updateSequential.script, data));
        if (!isInitial(e.touch.script)) e.touch = EngineDataArchetypeCallback(buildScript(e.touch.script, data));
        if (!isInitial(e.updateParallel.script)) e.updateParallel = EngineDataArchetypeCallback(buildScript(e.updateParallel.script, data));
        if (!isInitial(e.terminate.script)) e.terminate = EngineDataArchetypeCallback(buildScript(e.terminate.script, data)); 
    } 
    dataBuffer = compress_gzip(json_encode(data.toJsonObject()), 9);
}