#pragma once

class BackgroundConfiguration {
    public:

    string scope = "";
    double blur;
    string mask;

    Json::Value toJsonObject() {
        Json::Value res;
        if (scope != "") res["scope"] = scope;
        res["blur"] = blur;
        res["mask"] = mask;
        return res;
    }
}backgroundConfiguration;

class BackgroundDataFit {
    public:

    string width = "width";
    string height = "height";
    string contain = "contain";
    string cover = "cover";
}BackgroundDataFit;

class BackgroundData {
    public:

    double aspectRatio;
    string fit;
    string color;

    Json::Value toJsonObject() {
        Json::Value res;
        res["aspectRatio"] = aspectRatio;
        res["fit"] = fit;
        res["color"] = color;
        return res;
    }
}backgroundData;

string backgroundPath = "";
void defineBackground(string path, BackgroundData data, BackgroundConfiguration configuration) {
    backgroundPath = path;
    backgroundData = data;
    backgroundConfiguration = configuration;
}

void packBackground(string imagePath, string dataPath, string configPath) {
    cout << "Copying Background Image..." << endl;
    string texture = readFile(backgroundPath);
    writeFile(imagePath, texture);

    cout << "Writing Background Data..." << endl;
    Json::Value root = backgroundData.toJsonObject();
    string json = json_encode(root);
	buffer dataBuffer = compress_gzip(json);
    writeFile(dataPath, dataBuffer.asString());

    cout << "Writing Background Configuration..." << endl;
    root = backgroundConfiguration.toJsonObject();
    json = json_encode(root);
    dataBuffer = compress_gzip(json);
    writeFile(configPath, dataBuffer.asString());
}