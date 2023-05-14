#ifndef ENGINECONFIGURATION_H
#define ENGINECONFIGURATION_H

using namespace std;

int find(string goal, string source[], int n, bool asserted = true) {
    for (int i = 0; i < n; i++) if (goal == source[i]) return i;
    if (asserted) assert(false);
    return -1;
}

class EngineConfigurationSliderOption {
    public:

    string name;
    bool standard = true;
    string scope = "";
    string type = "slider";
    double def;
    double min;
    double max;
    double step;
    string unit = "";

    EngineConfigurationSliderOption(){}
    EngineConfigurationSliderOption(string name, double def, double min, double max, double step, bool standard = true, string scope = "", string unit = ""):
        name(name), def(def), min(min), max(max), step(step), standard(standard), scope(scope), unit(unit){}
    EngineConfigurationSliderOption(Json::Value arr) {
        name = arr["name"].asString();
        standard = arr["standard"].asBool();
        scope = arr["scope"].asString();
        def = arr["def"].asDouble();
        min = arr["min"].asDouble();
        max = arr["max"].asDouble();
        step = arr["step"].asDouble();
        unit = arr["unit"].asString();
    }

    Json::Value toJsonObject() {
        Json::Value res;
        res["name"] = name;
        res["standard"] = standard;
        res["scope"] = scope;
        res["type"] = type;
        res["def"] = def;
        res["min"] = min;
        res["max"] = max;
        res["step"] = step;
        res["unit"] = unit;
        return res;
    }
};

class EngineConfigurationToggleOption {
    public:

    string name;
    bool standard = true;
    string scope = "";
    string type = "toggle";
    bool def;

    EngineConfigurationToggleOption(){}
    EngineConfigurationToggleOption(string name, bool def, bool standard = true, string scope = ""):
        name(name), def(def), standard(standard), scope(scope){}
    EngineConfigurationToggleOption(Json::Value arr) {
        name = arr["name"].asString();
        standard = arr["standard"].asBool();
        scope = arr["scope"].asString();
        def = arr["def"].asInt();
    }

    Json::Value toJsonObject() {
        Json::Value res;
        res["name"] = name;
        res["standard"] = standard;
        res["scope"] = scope;
        res["type"] = type;
        res["def"] = def;
        return res;
    }
};

class EngineConfigurationSelectOption {
    public:

    string name;
    bool standard = true;
    string scope = "";
    string type = "select";
    int def;
    vector<string> values;

    EngineConfigurationSelectOption(){}
    EngineConfigurationSelectOption(string name, int def, vector<string> values, bool standard = true, string scope = ""):
        name(name), def(def), values(values), standard(standard), scope(scope){}
    EngineConfigurationSelectOption(Json::Value arr) {
        name = arr["name"].asString();
        standard = arr["standard"].asBool();
        scope = arr["scope"].asString();
        def = arr["def"].asInt();
        for (int i = 0; i < arr["values"].size(); i++) 
            values.push_back(arr["values"][i].asString());
    }

    void append(string value) {
        values.push_back(value);
    }

    Json::Value toJsonObject() {
        Json::Value res;
        res["name"] = name;
        res["standard"] = standard;
        res["scope"] = scope;
        res["type"] = type;
        res["def"] = def;
        res["values"].resize(0);
        for (int i = 0; i < values.size(); i++) res["values"].append(values[i]);
        return res;
    }
};

class EngineConfigurationOption {
    public:

    string type;
    EngineConfigurationSelectOption select;
    EngineConfigurationSliderOption slider;
    EngineConfigurationToggleOption toggle;

    EngineConfigurationOption(){}
    EngineConfigurationOption(EngineConfigurationSelectOption select): type("select"), select(select){}
    EngineConfigurationOption(EngineConfigurationSliderOption slider): type("slider"), slider(slider){}
    EngineConfigurationOption(EngineConfigurationToggleOption toggle): type("toggle"), toggle(toggle){}
    EngineConfigurationOption(Json::Value arr) {
        type = arr["type"].asString();
        if (type == "select") select = EngineConfigurationSelectOption(arr);
        else if (type == "slider") slider = EngineConfigurationSliderOption(arr);
        else if (type == "toggle") toggle = EngineConfigurationToggleOption(arr);
        else assert(false);
    }

    Json::Value toJsonObject() {
        if (type == "select") return select.toJsonObject();
        else if (type == "slider") return slider.toJsonObject();
        else if (type == "toggle") return toggle.toJsonObject();
        else assert(false);
    }
};

class EngineConfigurationVisibility {
    public:

    double scale;
    double alpha;

    EngineConfigurationVisibility(){}
    EngineConfigurationVisibility(double scale, double alpha): scale(scale), alpha(alpha){}
    EngineConfigurationVisibility(Json::Value arr){scale = arr["scale"].asDouble(), alpha = arr["alpha"].asDouble();}

    Json::Value toJsonObject() {
        Json::Value res;
        res["scale"] = scale;
        res["alpha"] = alpha;
        return res;
    }
};

class EngineConfigurationAnimationTween {
    public:
    
    double from;
    double to;
    double duration;
    EngineConfigurationAnimationEase ease;
    
    EngineConfigurationAnimationTween(){}
    EngineConfigurationAnimationTween(double from, double to, double duration, EngineConfigurationAnimationEase ease):
        from(from), to(to), duration(duration), ease(ease){}
    EngineConfigurationAnimationTween(Json::Value arr) {
        from = arr["from"].asDouble();
        to = arr["to"].asDouble();
        duration = arr["duration"].asDouble();
        ease = (EngineConfigurationAnimationEase)find(arr["ease"].asString(), EngineConfigurationAnimationEaseString, 34);
    }

    Json::Value toJsonObject() {
        Json::Value res;
        res["from"] = from;
        res["to"] = to;
        res["duration"] = duration;
        res["ease"] = EngineConfigurationAnimationEaseString[ease];
        return res;
    }
};

class EngineConfigurationAnimation {
    public:

    EngineConfigurationAnimationTween scale;
    EngineConfigurationAnimationTween alpha;
    
    EngineConfigurationAnimation(){}
    EngineConfigurationAnimation(EngineConfigurationAnimationTween scale, EngineConfigurationAnimationTween alpha): scale(scale), alpha(alpha){}
    EngineConfigurationAnimation(Json::Value arr) {
        scale = EngineConfigurationAnimationTween(arr["scale"]);
        alpha = EngineConfigurationAnimationTween(arr["alpha"]);
    }

    Json::Value toJsonObject() {
        Json::Value res;
        res["scale"] = scale.toJsonObject();
        res["alpha"] = alpha.toJsonObject();
        return res;
    }
};

class EngineConfigurationUI {
    public:

    string scope = "";
    EngineConfigurationMetric primaryMetric;
    EngineConfigurationMetric secondaryMetric;
    EngineConfigurationVisibility menuVisibility;
    EngineConfigurationVisibility judgmentVisibility;
    EngineConfigurationVisibility comboVisibility;
    EngineConfigurationVisibility primaryMetricVisibility;
    EngineConfigurationVisibility secondaryMetricVisbility;
    EngineConfigurationAnimation judgmentAnimation;
    EngineConfigurationAnimation comboAnimation;
    EngineConfigurationjudgmentErrorStyle judgmentErrorStyle;
    EngineConfigurationjudgmentErrorPlacement judgmentErrorPlacement;
    int judgmentErrorMin;

    EngineConfigurationUI(){}
    EngineConfigurationUI(EngineConfigurationMetric primaryMetric, EngineConfigurationMetric secondaryMetric,
        EngineConfigurationVisibility menuVisibility, EngineConfigurationVisibility judgmentVisibility,
        EngineConfigurationVisibility comboVisibility, EngineConfigurationVisibility primaryMetricVisibility, EngineConfigurationVisibility secondaryMetricVisbility,
        EngineConfigurationAnimation judgmentAnimation, EngineConfigurationAnimation comboAnimation,
        EngineConfigurationjudgmentErrorStyle judgmentErrorStyle, EngineConfigurationjudgmentErrorPlacement judgmentErrorPlacement,
        int judgmentErrorMin, string scope = ""):
        primaryMetric(primaryMetric), secondaryMetric(secondaryMetric),
        menuVisibility(menuVisibility), judgmentVisibility(judgmentVisibility),
        comboVisibility(comboVisibility), primaryMetricVisibility(primaryMetricVisibility), secondaryMetricVisbility(secondaryMetricVisbility),
        judgmentAnimation(judgmentAnimation), comboAnimation(comboAnimation),
        judgmentErrorStyle(judgmentErrorStyle), judgmentErrorPlacement(judgmentErrorPlacement),
        judgmentErrorMin(judgmentErrorMin), scope(scope){}
    EngineConfigurationUI(Json::Value arr) {
        scope = arr["scope"].asString();
        primaryMetric = (EngineConfigurationMetric)find(arr["primaryMetric"].asString(), EngineConfigurationMetricString, 5);
        secondaryMetric = (EngineConfigurationMetric)find(arr["secondaryMetric"].asString(), EngineConfigurationMetricString, 5);
        menuVisibility = EngineConfigurationVisibility(arr["menuVisibility"]);
        judgmentVisibility = EngineConfigurationVisibility(arr["judgmentVisibility"]);
        comboVisibility = EngineConfigurationVisibility(arr["comboVisibility"]);
        primaryMetricVisibility = EngineConfigurationVisibility(arr["primaryMetrocVisibility"]);
        secondaryMetricVisbility = EngineConfigurationVisibility(arr["secondaryMetricVisibility"]);
        judgmentAnimation = EngineConfigurationAnimation(arr["judgmentAnimation"]);
        comboAnimation = EngineConfigurationAnimation(arr["comboAnimation"]);
        judgmentErrorStyle = (EngineConfigurationjudgmentErrorStyle)find(arr["judgmentErrorStyle"].asString(), EngineConfigurationjudgmentErrorStyleString, 11);
        judgmentErrorPlacement = (EngineConfigurationjudgmentErrorPlacement)find(arr["judgmentErrorPlacement"].asString(), EngineConfigurationjudgmentErrorPlacementString, 3);
        judgmentErrorMin = arr["judgmentErrorMin"].asInt();
    }

    Json::Value toJsonObject() {
        Json::Value res;
        res["scope"] = scope;
        res["primaryMetric"] = EngineConfigurationMetricString[primaryMetric];
        res["secondaryMetric"] = EngineConfigurationMetricString[secondaryMetric];
        res["menuVisibility"] = menuVisibility.toJsonObject();
        res["judgmentVisibility"] = judgmentVisibility.toJsonObject();
        res["comboVisibility"] = comboVisibility.toJsonObject();
        res["primaryMetricVisibility"] = primaryMetricVisibility.toJsonObject();
        res["secondaryMetricVisibility"] = secondaryMetricVisbility.toJsonObject();
        res["judgmentAnimation"] = judgmentAnimation.toJsonObject();
        res["comboAnimation"] = comboAnimation.toJsonObject();
        res["judgmentErrorStyle"] = EngineConfigurationjudgmentErrorStyleString[judgmentErrorStyle];
        res["judgmentErrorPlacement"] = EngineConfigurationjudgmentErrorPlacementString[judgmentErrorPlacement];
        res["judgmentErrorMin"] = judgmentErrorMin;
        return res;
    }
};

class EngineConfiguration {
    public:

    vector<EngineConfigurationOption> options;
    EngineConfigurationUI ui;

    EngineConfiguration(){}
    EngineConfiguration(vector<EngineConfigurationOption> options, EngineConfigurationUI ui): options(options), ui(ui){}
    EngineConfiguration(Json::Value arr) {
        for (int i = 0; i < arr["options"].size(); i++) options.push_back(EngineConfigurationOption(arr["options"][i]));
        ui = EngineConfigurationUI(arr["ui"]);
    }

    Json::Value toJsonObject() {
        Json::Value res;
        res["options"].resize(0);
        for (int i = 0; i < options.size(); i++) res["options"].append(options[i].toJsonObject());
        res["ui"] = ui.toJsonObject();
        return res;
    }
};

#endif