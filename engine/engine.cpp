string scope = "test";

#include"skins.cpp"
#include"backgrounds.cpp"
#include"effects.cpp"
#include"particles.cpp"

#ifdef play
using namespace playData;

#elif tutorial
using namespace tutorialData;

#elif preview
using namespace previewData;

#elif watch
using namespace watchData;

#endif