#ifndef ENGINEDATA_H
#define ENGINEDATA_H

using namespace std;

class EngineDataBucketSprite {
    public:

    int id;
    double x;
    double y;
    double w;
    double h;
    double rotation;
	int fallbackId = 0;

    EngineDataBucketSprite(){}
    EngineDataBucketSprite(int id, double x, double y, double w, double h, double rotation, int fallbackId = 0):
        id(id), x(x), y(y), w(w), h(h), rotation(rotation), fallbackId(fallbackId){}
    EngineDataBucketSprite(Json::Value arr) {
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

    vector<EngineDataBucketSprite> sprites;
    string unit = "";

    EngineDataBucket(){}
    EngineDataBucket(Json::Value arr, string unit = ""): unit(unit) {
        for (int i = 0; i < arr["sprites"].size(); i++) sprites.push_back(EngineDataBucketSprite(arr["sprites"][i]));
    }
	EngineDataBucket(vector<EngineDataBucketSprite> sprites, string unit = ""): sprites(sprites), unit(unit){}

    void append(EngineDataBucketSprite sprite) {
        sprites.push_back(sprite);
    }

    Json::Value toJsonObject() {
        Json::Value res;
        res["sprites"].resize(0);
        for (int i = 0; i < sprites.size(); i++) res["sprites"].append(sprites[i].toJsonValue());
        return res;
    }
};

class EngineDataArchetypeCallback {
    public:

    double index;
    double order = 0;
    FuncNode script = -1;

    EngineDataArchetypeCallback(){}
    EngineDataArchetypeCallback(double index, double order): index(index), order(order){};
    EngineDataArchetypeCallback(Json::Value arr){
        if (arr.isNull() == true) return;
        index = arr["index"].asInt(), order = arr["order"].asInt();
    }
    EngineDataArchetypeCallback(FuncNode script):script(script){}
	EngineDataArchetypeCallback(double value):script(FuncNode(value)){}

    Json::Value toJsonObject() {
        Json::Value res;
        res["index"] = index;
        res["order"] = order;
        return res;
    }
};

class EngineDataArchetype {
    public:

    string name;
    bool hasInput;
    EngineDataArchetypeCallback preprocess;
    EngineDataArchetypeCallback spawnOrder;
    EngineDataArchetypeCallback shouldSpawn;
    EngineDataArchetypeCallback initialize;
    EngineDataArchetypeCallback updateSequential;
    EngineDataArchetypeCallback touch;
    EngineDataArchetypeCallback updateParallel;
    EngineDataArchetypeCallback terminate;
    vector<pair<string, double> > data;

    EngineDataArchetype(){}
    EngineDataArchetype(string name, bool hasInput, vector<pair<string, double> > data,
        EngineDataArchetypeCallback preprocess = EngineDataArchetypeCallback(),
        EngineDataArchetypeCallback spawnOrder = EngineDataArchetypeCallback(),
        EngineDataArchetypeCallback shouldSpawn = EngineDataArchetypeCallback(),
        EngineDataArchetypeCallback initialize = EngineDataArchetypeCallback(),
        EngineDataArchetypeCallback updateSequential = EngineDataArchetypeCallback(),
        EngineDataArchetypeCallback touch = EngineDataArchetypeCallback(),
        EngineDataArchetypeCallback updateParallel = EngineDataArchetypeCallback(),
        EngineDataArchetypeCallback terminate = EngineDataArchetypeCallback()): 
        name(name), hasInput(hasInput), data(data), preprocess(preprocess), spawnOrder(spawnOrder), shouldSpawn(shouldSpawn), initialize(initialize), updateSequential(updateSequential), touch(touch), updateParallel(updateParallel), terminate(terminate){};
    EngineDataArchetype(Json::Value arr) {
        name = arr["name"].asString();
        hasInput = arr["hasInput"].asBool();
        preprocess = EngineDataArchetypeCallback(arr["preprocess"]);
        spawnOrder = EngineDataArchetypeCallback(arr["spawnOrder"]);
        shouldSpawn = EngineDataArchetypeCallback(arr["shouldSpawn"]);
        initialize = EngineDataArchetypeCallback(arr["initialize"]);
        updateSequential = EngineDataArchetypeCallback(arr["updateSequential"]);
        touch = EngineDataArchetypeCallback(arr["touch"]);
        updateParallel = EngineDataArchetypeCallback(arr["updateParallel"]);
        terminate = EngineDataArchetypeCallback(arr["terminate"]);
        for (int i = 0; i < arr["data"].size(); i++) data.push_back(make_pair(arr["data"][i]["name"].asString(), arr["data"][i]["index"].asDouble()));
    }

    Json::Value toJsonObject() {
        Json::Value res;
        res["name"] = name;
        res["hasInput"] = hasInput;
        res["preprocess"] = preprocess.toJsonObject();
        res["spawnOrder"] = spawnOrder.toJsonObject();
        res["shouldSpawn"] = shouldSpawn.toJsonObject();
        res["initialize"] = initialize.toJsonObject();
        res["updateSequential"] = updateSequential.toJsonObject();
        res["touch"] = touch.toJsonObject();
        res["updateParallel"] = updateParallel.toJsonObject();
        res["terminate"] = terminate.toJsonObject();
        res["data"].resize(0);
        for (int i = 0; i < data.size(); i++) {
            res["data"][i]["name"] = data[i].first;
            res["data"][i]["index"] = data[i].second;
        }
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

    RuntimeFunction func;
    vector<double> args;

    EngineDataFunctionNode(){}
    EngineDataFunctionNode(RuntimeFunction func, vector<double> args): func(func), args(args){}
    EngineDataFunctionNode(Json::Value arr) {
        func = (RuntimeFunction)find(arr["func"].asString(), RuntimeFunctionString, 185);
        for (int i = 0; i < arr["args"].size(); i++) args.push_back(arr["args"][i].asDouble());
    }

    Json::Value toJsonObject() {
        Json::Value res;
        res["func"] = RuntimeFunctionString[func];
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

    vector<pair<string, int> > skin_sprites;
    vector<pair<string, int> > effect_clips;
    vector<pair<string, int> > particle_effects;
    vector<EngineDataBucket> buckets;
    vector<EngineDataArchetype> archetypes;
    vector<EngineDataNode> nodes;

    EngineData(){}
    EngineData(
        vector<pair<string, int> > skin_sprites, vector<pair<string, int> > effect_clips, vector<pair<string, int> > particle_effects,
        vector<EngineDataBucket> buckets, vector<EngineDataArchetype> archetypes, vector<EngineDataNode> nodes): 
        skin_sprites(skin_sprites), effect_clips(effect_clips), particle_effects(particle_effects), buckets(buckets), archetypes(archetypes), nodes(nodes){}
    EngineData(Json::Value arr) {
        for (int i = 0; i < arr["skin"]["sprites"].size(); i++) skin_sprites.push_back(make_pair(arr["skin"]["sprites"][i]["name"].asString(), arr["skin"]["sprites"][i]["id"].asInt()));
        for (int i = 0; i < arr["effect"]["clips"].size(); i++) effect_clips.push_back(make_pair(arr["effect"]["clips"][i]["name"].asString(), arr["effect"]["clips"][i]["id"].asInt()));
        for (int i = 0; i < arr["particle"]["effects"].size(); i++) particle_effects.push_back(make_pair(arr["particle"]["effects"][i]["name"].asString(), arr["particle"]["effects"][i]["id"].asInt()));
        for (int i = 0; i < arr["buckets"].size(); i++) buckets.push_back(EngineDataBucket(arr["buckets"][i]));
        for (int i = 0; i < arr["archetypes"].size(); i++) archetypes.push_back(EngineDataArchetype(arr["archetypes"][i]));
        for (int i = 0; i < arr["nodes"].size(); i++) nodes.push_back(EngineDataNode(arr["nodes"][i]));
    }

    Json::Value toJsonObject() {
        Json::Value res;
        res["skin"]["sprites"].resize(0); res["effect"]["clips"].resize(0); res["particle"]["effects"].resize(0);
        res["buckets"].resize(0); res["archetypes"].resize(0); res["nodes"].resize(0);
        for (int i = 0; i < skin_sprites.size(); i++) {
            res["skin"]["sprites"][i]["name"] = skin_sprites[i].first;
            res["skin"]["sprites"][i]["id"] = skin_sprites[i].second;
        }
        for (int i = 0; i < effect_clips.size(); i++) {
            res["effect"]["clips"][i]["name"] = effect_clips[i].first;
            res["effect"]["clips"][i]["id"] = effect_clips[i].second;
        }
        for (int i = 0; i < particle_effects.size(); i++) {
            res["particle"]["effects"][i]["name"] = particle_effects[i].first;
            res["particle"]["effects"][i]["id"] = particle_effects[i].second;
        }
        for (int i = 0; i < buckets.size(); i++) res["buckets"].append(buckets[i].toJsonObject());
        for (int i = 0; i < archetypes.size(); i++) res["archetypes"].append(archetypes[i].toJsonObject());
        for (int i = 0; i < nodes.size(); i++) res["nodes"].append(nodes[i].toJsonObject());
        return res;
    }
};

#endif
