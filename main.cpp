#include<bits/stdc++.h>
#include"sonolus/sonolus.h"
using namespace std;

const string scope = "";
int main(int argc, char** argv) {
    UI.SetScope(scope);
    UI.SetMenu(Visibility(1.0, 1.0));
    UI.SetJudgment(
        Visibility(1.0, 1.0), 
        Animation(
            AnimationTween(0.6, 1.0, 0.1, EngineConfigurationAnimationTweenEase.InSine),
            AnimationTween(0.6, 1.0, 0.1, EngineConfigurationAnimationTweenEase.InSine)
        ),
        EngineConfigurationJudgmentErrorStyle.None,
        EngineConfigurationJudgmentErrorPlacement.LeftRight,
        20.0
    );
    UI.SetCombo(
        Visibility(1.0, 1.0),
        Animation(
            AnimationTween(0.6, 1.0, 0.1, EngineConfigurationAnimationTweenEase.InSine),
            AnimationTween(0.6, 1.0, 0.1, EngineConfigurationAnimationTweenEase.Linear)
        )
    );
    UI.SetMetric(
        EngineConfigurationMetric.Arcade,
        Visibility(1.0, 1.0),
        EngineConfigurationMetric.Life,
        Visibility(1.0, 1.0)
    );
    UI.SetProgress(Visibility(1.0, 1.0));
    UI.SetTutorial(
        Visibility(1.0, 1.0),
        Visibility(1.0, 1.0)
    );
    BuildConfiguration();

    #ifdef play
    BuildData(
        Archetype
        /* Write you code here */
    );
    #endif
    #ifdef tutorial
    BuildData();
    #endif
    #ifdef preview
    BuildData(
        Archetype
        /* Write you code here */
    );
    #endif
    #ifdef watch
    BuildData(
        Archetype
        /* Write you code here */
    );
    #endif
    
    PackSkin();
    PackEffect();
}