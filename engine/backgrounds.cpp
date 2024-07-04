bool unused_background_unused = [](){
    defineBackground("background/background.png", {
        aspectRatio: 1920.0 / 1080.0,
        fit: BackgroundDataFit.cover,
        color: "#000000"
    }, {
        scope: Scope,
        blur: 0.0,
        mask: "#000000"
    });
    return true;
}();