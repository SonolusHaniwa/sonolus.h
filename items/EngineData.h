#ifndef ENGINEDATA_H
#define ENGINEDATA_H

using namespace std;
typedef int SkinSprite;

class EngineDataSprite {
    public:

    SkinSprite id;
    SkinSprite fallbackId = 0;
    double x;
    double y;
    double w;
    double h;
    double rotation;

    EngineDataSprite(){}
    EngineDataSprite(SkinSprite id, double x, double y, double w, double h, double rotation, SkinSprite fallbackId = 0):
        id(id), x(x), y(y), w(w), h(h), rotation(rotation), fallbackId(fallbackId){}
    EngineDataSprite(Json::Value arr) {
        id = arr["id"].asInt();
        fallbackId = arr["fallbackId"].asInt();
        x = arr["x"].asDouble();
        y = arr["y"].asDouble();
        w = arr["w"].asDouble();
        h = arr["h"].asDouble();
        rotation = arr["rotation"].asDouble();
    }

    Json::Value toJsonValue() {
        Json::Value res;
        res["id"] = id;
        res["fallbackId"] = fallbackId;
        res["x"] = x;
        res["y"] = y;
        res["w"] = w;
        res["h"] = h;
        res["rotation"] = rotation;
        return res;
    }
};

class EngineDataBucket{
    public:

    vector<EngineDataSprite> sprites;

    EngineDataBucket(){}
    EngineDataBucket(Json::Value arr) {
        for (int i = 0; i < arr["sprites"].size(); i++) sprites.push_back(EngineDataSprite(arr["sprites"][i]));
    }

    void append(EngineDataSprite sprite) {
        sprites.push_back(sprite);
    }

    Json::Value toJsonObject() {
        Json::Value res;
        res["sprites"].resize(0);
        for (int i = 0; i < sprites.size(); i++) res["sprites"].append(sprites[i].toJsonValue());
        return res;
    }
};

class EngineDataArchetype {
    public:

    int script;
    int data_index = 0;
    vector<int> data_values;
    bool input = true;

    EngineDataArchetype(){}
    EngineDataArchetype(int script, int data_index = 0, vector<int> data_values = vector<int>(), bool input = true):
        script(script), data_index(data_index), data_values(data_values), input(input){}
    EngineDataArchetype(Json::Value arr) {
        script = arr["script"].asInt();
        data_index = arr["data"]["index"].asInt();
        for (int i = 0; i < arr["data"]["values"].size(); i++) data_values.push_back(arr["data"]["values"][i].asInt());
        input = arr["input"].asBool();
    }

    Json::Value toJsonObject() {
        Json::Value res;
        res["script"] = script;
        res["data"]["index"] = data_index;
        res["data"]["values"].resize(0);
        for (int i = 0; i < data_values.size(); i++) res["data"]["values"].append(data_values[i]);
        res["input"] = input;
        return res;
    }
};

class EngineDataScriptCallback {
    public:

    int index = -1;
    int order = 0;
    FuncNode script = -1;

    EngineDataScriptCallback(){}
    EngineDataScriptCallback(int index, int order = 0): index(index), order(order){}
    EngineDataScriptCallback(Json::Value arr){
        if (arr.isNull() == true) return;
        index = arr["index"].asInt(), order = arr["order"].asInt();
    }
    EngineDataScriptCallback(FuncNode script):script(script){}

    Json::Value toJsonObject() {
        Json::Value res;
        res["index"] = index;
        res["order"] = order;
        return res;
    }
};

class EngineDataScript {
    public:

    EngineDataScriptCallback preprocess;
    EngineDataScriptCallback spawnOrder;
    EngineDataScriptCallback shouldSpawn;
    EngineDataScriptCallback initialize;
    EngineDataScriptCallback updateSequential;
    EngineDataScriptCallback touch;
    EngineDataScriptCallback updateParallel;
    EngineDataScriptCallback terminate;

    EngineDataScript(EngineDataScriptCallback preprocess = EngineDataScriptCallback(),
        EngineDataScriptCallback spawnOrder = EngineDataScriptCallback(),
        EngineDataScriptCallback shouldSpawn = EngineDataScriptCallback(),
        EngineDataScriptCallback initialize = EngineDataScriptCallback(),
        EngineDataScriptCallback updateSequential = EngineDataScriptCallback(),
        EngineDataScriptCallback touch = EngineDataScriptCallback(),
        EngineDataScriptCallback updateParallel = EngineDataScriptCallback(),
        EngineDataScriptCallback terminate = EngineDataScriptCallback()):
        preprocess(preprocess), spawnOrder(spawnOrder), shouldSpawn(shouldSpawn),
        initialize(initialize), updateSequential(updateSequential), touch(touch),
        updateParallel(updateParallel), terminate(terminate){}
    EngineDataScript(Json::Value arr) {
        preprocess = EngineDataScriptCallback(arr["preprocess"]);
        spawnOrder = EngineDataScriptCallback(arr["spawnOrder"]);
        shouldSpawn = EngineDataScriptCallback(arr["shouldSpawn"]);
        initialize = EngineDataScriptCallback(arr["initialize"]);
        updateSequential = EngineDataScriptCallback(arr["updateSequential"]);
        touch = EngineDataScriptCallback(arr["touch"]);
        updateParallel = EngineDataScriptCallback(arr["updateParallel"]);
        terminate = EngineDataScriptCallback(arr["terminate"]);
    }

    Json::Value toJsonObject() {
        Json::Value res = Json::objectValue;
        if (preprocess.index != -1) res["preprocess"] = preprocess.toJsonObject();
        if (spawnOrder.index != -1) res["spawnOrder"] = spawnOrder.toJsonObject();
        if (shouldSpawn.index != -1) res["shouldSpawn"] = shouldSpawn.toJsonObject();
        if (initialize.index != -1) res["initialize"] = initialize.toJsonObject();
        if (updateSequential.index != -1) res["updateSequential"] = updateSequential.toJsonObject();
        if (touch.index != -1) res["touch"] = touch.toJsonObject();
        if (updateParallel.index != -1) res["updateParallel"] = updateParallel.toJsonObject();
        if (terminate.index != -1) res["terminate"] = terminate.toJsonObject();
        return res;
    }
};

class EngineDataValueNode {
    public:

    double value;

    EngineDataValueNode(){}
    EngineDataValueNode(float value): value(value){};
    EngineDataValueNode(Json::Value arr){value = arr["value"].asDouble();}

    Json::Value toJsonObject() {
        Json::Value res;
        res["value"] = value;
        return res;
    }
};

class EngineDataFunctionNode {
    public:

    EngineDataFunctionName func;
    vector<double> args;

    EngineDataFunctionNode(){}
    EngineDataFunctionNode(EngineDataFunctionName func, vector<double> args): func(func), args(args){}
    EngineDataFunctionNode(Json::Value arr) {
        func = (EngineDataFunctionName)find(arr["func"].asString(), EngineDataFunctionNameString, 121);
        for (int i = 0; i < arr["args"].size(); i++) args.push_back(arr["args"][i].asDouble());
    }

    Json::Value toJsonObject() {
        Json::Value res;
        res["func"] = EngineDataFunctionNameString[func];
        res["args"].resize(0);
        for (int i = 0; i < args.size(); i++) res["args"].append(args[i]);
        return res;
    }
};

class EngineDataNode {
    public:

    string type = "value";
    EngineDataValueNode value;
    EngineDataFunctionNode func;

    EngineDataNode(){}
    EngineDataNode(EngineDataValueNode value): type("value"), value(value){}
    EngineDataNode(EngineDataFunctionNode func): type("func"), func(func){}
    EngineDataNode(Json::Value arr) {
        if (arr["value"].isDouble()) type = "value", value = EngineDataValueNode(arr);
        else type = "func", func = EngineDataFunctionNode(arr);
    }

    bool operator < (const EngineDataNode& a) const {
        if (a.type != type) return type < a.type;
        if (a.type == "value") return value.value < a.value.value;
        else if (func.args == a.func.args) return func.func < a.func.func;
        else return func.args < a.func.args;
    }

    Json::Value toJsonObject() {
        if (type == "value") return value.toJsonObject();
        else return func.toJsonObject();
    }
};

class EngineData {
    public:

    vector<EngineDataBucket> buckets;
    vector<EngineDataArchetype> archetypes;
    vector<EngineDataScript> scripts;
    vector<EngineDataNode> nodes;

    EngineData(){}
    EngineData(vector<EngineDataBucket> buckets, vector<EngineDataArchetype> archetypes,
        vector<EngineDataScript> scripts, vector<EngineDataNode> nodes): buckets(buckets), archetypes(archetypes), scripts(scripts), nodes(nodes){}
    EngineData(Json::Value arr) {
        for (int i = 0; i < arr["buckets"].size(); i++) buckets.push_back(EngineDataBucket(arr["buckets"][i]));
        for (int i = 0; i < arr["archetypes"].size(); i++) archetypes.push_back(EngineDataArchetype(arr["archetypes"][i]));
        for (int i = 0; i < arr["scripts"].size(); i++) scripts.push_back(EngineDataScript(arr["scripts"][i]));
        for (int i = 0; i < arr["nodes"].size(); i++) nodes.push_back(EngineDataNode(arr["nodes"][i]));
    }

    Json::Value toJsonObject() {
        Json::Value res;
        res["buckets"].resize(0); res["archetypes"].resize(0);
        res["scripts"].resize(0); res["nodes"].resize(0);
        for (int i = 0; i < buckets.size(); i++) res["buckets"].append(buckets[i].toJsonObject());
        for (int i = 0; i < archetypes.size(); i++) res["archetypes"].append(archetypes[i].toJsonObject());
        for (int i = 0; i < scripts.size(); i++) res["scripts"].append(scripts[i].toJsonObject());
        for (int i = 0; i < nodes.size(); i++) res["nodes"].append(nodes[i].toJsonObject());
        return res;
    }
};

#endif