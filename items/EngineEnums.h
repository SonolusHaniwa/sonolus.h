#ifndef ENGINEENUMS_H
#define ENGINEENUMS_H

using namespace std;

class NameText {
    public:

    string Keywords = "#KEYWORDS";
    string Name = "#NAME";
    string Rating = "#RATING";
    string MinimumRating = "#RATING_MINIMUM";
    string MaximumRating = "#RATING_MAXIMUM";
    string Title = "#TITLE";
    string Subtitle = "#SUBTITLE";
    string Artists = "#ARTISTS";
    string Author = "#AUTHOR";
    string Genre = "#GENRE";
    string Category = "#CATEGORY";
    string Language = "#LANGUAGE";
    string Difficulty = "#DIFFICULTY";
    string Length = "#LENGTH";
    string MinimumLength = "#LENGTH_MINIMUM";
    string MaximumLength = "#LENGTH_MAXIMUM";
    string LevelSpeed = "#SPEED";
    string AutoPlay = "#AUTO";
    string MirrorLevel = "#MIRROR";
    string Random = "#RANDOM";
    string Hidden = "#HIDDEN";
    string StrictJudgment = "#JUDGMENT_STRICT";
    string LooseJudgment = "#JUDGMENT_LOOSE";
    string SFX = "#EFFECT";
    string AutoSFX = "#EFFECT_AUTO";
    string StageVisibility = "#STAGE";
    string StagePosition = "#STAGE_POSITION";
    string StageSize = "#STAGE_SIZE";
    string StageRotation = "#STAGE_ROTATION";
    string StageTransparency = "#STAGE_ALPHA";
    string StageAnimation = "#STAGE_ANIMATION";
    string StageTilt = "#STAGE_TILT";
    string VerticalStageCover = "#STAGE_COVER_VERTICAL";
    string HorizontalStageCover = "#STAGE_COVER_HORIZONTAL";
    string StageCoverTransparency = "#STAGE_COVER_ALPHA";
    string LockStageAspectRatio = "#STAGE_ASPECTRATIO_LOCK";
    string StageEffect = "#STAGE_EFFECT";
    string StageEffectPosition = "#STAGE_EFFECT_POSITION";
    string StageEffectSize = "#STAGE_EFFECT_SIZE";
    string StageEffectRotation = "#STAGE_EFFECT_ROTATION";
    string StageEffectTransparency = "#STAGE_EFFECT_ALPHA";
    string LaneVisibility = "#LANE";
    string LanePosition = "#LANE_POSITION";
    string LaneSize = "#LANE_SIZE";
    string LaneRotation = "#LANE_ROTATION";
    string LaneTransparency = "#LANE_ALPHA";
    string LaneAnimation = "#LANE_ANIMATION";
    string LaneEffect = "#LANE_EFFECT";
    string LaneEffectPosition = "#LANE_EFFECT_POSITION";
    string LaneEffectSize = "#LANE_EFFECT_SIZE";
    string LaneEffectRotation = "#LANE_EFFECT_ROTATION";
    string LaneEffectTransparency = "#LANE_EFFECT_ALPHA";
    string JudgmentLineVisibility = "#JUDGELINE";
    string JudgmentLinePosition = "#JUDGELINE_POSITION";
    string JudgmentLineSize = "#JUDGELINE_SIZE";
    string JudgmentLineRotation = "#JUDGELINE_ROTATION";
    string JudgmentLineTransparency = "#JUDGELINE_ALPHA";
    string JudgmentLineAnimation = "#JUDGELINE_ANIMATION";
    string JudgmentLineEffect = "#JUDGELINE_EFFECT";
    string JudgmentLineEffectPosition = "#JUDGELINE_EFFECT_POSITION";
    string JudgmentLineEffectSize = "#JUDGELINE_EFFECT_SIZE";
    string JudgmentLineEffectRotation = "#JUDGELINE_EFFECT_ROTATION";
    string JudgmentLineEffectTransparency = "#JUDGELINE_EFFECT_ALPHA";
    string SlotVisibility = "#SLOT";
    string SlotPosition = "#SLOT_POSITION";
    string SlotSize = "#SLOT_SIZE";
    string SlotRotation = "#SLOT_ROTATION";
    string SlotTransparency = "#SLOT_ALPHA";
    string SlotAnimation = "#SLOT_ANIMATION";
    string SlotEffect = "#SLOT_EFFECT";
    string SlotEffectPosition = "#SLOT_EFFECT_POSITION";
    string SlotEffectSize = "#SLOT_EFFECT_SIZE";
    string SlotEffectRotation = "#SLOT_EFFECT_ROTATION";
    string SlotEffectTransparency = "#SLOT_EFFECT_ALPHA";
    string NoteVisibility = "#NOTE";
    string NoteSpeed = "#NOTE_SPEED";
    string RandomNoteSpeed = "#NOTE_SPEED_RANDOM";
    string NotePosition = "#NOTE_POSITION";
    string NoteSize = "#NOTE_SIZE";
    string NoteRotation = "#NOTE_ROTATION";
    string NoteTransparency = "#NOTE_ALPHA";
    string NoteAnimation = "#NOTE_ANIMATION";
    string NoteEffect = "#NOTE_EFFECT";
    string NoteEffectPosition = "#NOTE_EFFECT_POSITION";
    string NoteEffectSize = "#NOTE_EFFECT_SIZE";
    string NoteEffectRotation = "#NOTE_EFFECT_ROTATION";
    string NoteEffectTransparency = "#NOTE_EFFECT_ALPHA";
    string MarkerVisibility = "#MARKER";
    string MarkerPosition = "#MARKER_POSITION";
    string MarkerSize = "#MARKER_SIZE";
    string MarkerRotation = "#MARKER_ROTATION";
    string MarkerTransparency = "#MARKER_ALPHA";
    string MarkerAnimation = "#MARKER_ANIMATION";
    string ConnectorVisibility = "#CONNECTOR";
    string ConnectorPosition = "#CONNECTOR_POSITION";
    string ConnectorSize = "#CONNECTOR_SIZE";
    string ConnectorRotation = "#CONNECTOR_ROTATION";
    string ConnectorTransparency = "#CONNECTOR_ALPHA";
    string ConnectorAnimation = "#CONNECTOR_ANIMATION";
    string SimultaneousLineVisibility = "#SIMLINE";
    string SimultaneousLinePosition = "#SIMLINE_POSITION";
    string SimultaneousLineSize = "#SIMLINE_SIZE";
    string SimultaneousLineRotation = "#SIMLINE_ROTATION";
    string SimultaneousLineTransparency = "#SIMLINE_ALPHA";
    string SimultaneousLineAnimation = "#SIMLINE_ANIMATION";
}NameText;

class UnitText {
    public:

    string Percentage = "#PERCENTAGE";
    string Second = "#SECOND";
    string Millisecond = "#MILLISECOND";
}UnitText;

class InstructionText {
    public:

    string Tap = "#TAP";
    string TapAndHold = "#TAP_HOLD";
    string TapAndRelease = "#TAP_RELEASE";
    string TapAndFlick = "#TAP_FLICK";
    string TapAndSlide = "#TAP_SLIDE";
    string Hold = "#HOLD";
    string HoldAndSlide = "#HOLD_SLIDE";
    string HoldAndFollow = "#HOLD_FOLLOW";
    string Release = "#RELEASE";
    string Flick = "#FLICK";
    string Slide = "#SLIDE";
    string SlideAndFlick = "#SLIDE_FLICK";
    string Avoid = "#AVOID";
    string Jiggle = "#JIGGLE";
}InstructionText;

class InstructionIconName {
    public:
    
    string Hand = "#HAND";
    string Arrow = "#ARROW";
}InstructionIconName;

class OptionType {
    public:

    string Toggle = "toggle";
    string Slider = "slider";
    string Select = "select";
}OptionType;

class Metric {
    public:

    string arcade = "arcade";
    string accuracy = "accuracy";
    string life = "life";
    string perfectRate = "perfectRate";
    string errorHeatmap = "errorHeatmap";
}Metric;

class AnimationEase {
    public:

    string Linear = "Linear";
    string InSine = "InSine";
    string InQuad = "InQuad";
    string InCubic = "InCubic";
    string InQuart = "InQuart";
    string InExpo = "InExpo";
    string InCirc = "InCirc";
    string InBack = "InBack";
    string InElastic = "InElastic";
    string OutSine = "OutSine";
    string OutQuad = "OutQuad";
    string OutCubic = "OutCubic";
    string OutQuart = "OutQuart";
    string OutExpo = "OutExpo";
    string OutCirc = "OutCirc";
    string OutBack = "OutBack";
    string OutElastic = "OutElastic";
    string InOutSine = "InOutSine";
    string InOutQuad = "InOutQuad";
    string InOutCubic = "InOutCubic";
    string InOutQuart = "InOutQuart";
    string InOutExpo = "InOutExpo";
    string InOutCirc = "InOutCirc";
    string InOutBack = "InOutBack";
    string InOutElastic = "InOutElastic";
    string OutInSine = "OutInSine";
    string OutInQuad = "OutInQuad";
    string OutInCubic = "OutInCubic";
    string OutInQuart = "OutInQuart";
    string OutInExpo = "OutInExpo";
    string OutInCirc = "OutInCirc";
    string OutInBack = "OutInBack";
    string OutInElastic = "OutInElastic";
    string None = "None";
}AnimationEase;

class ErrorStyle {
    public:

    string none = "none";
    string plus = "plus";
    string minus = "minus";
    string arrowUp = "arrowUp";
    string arrowDown = "arrowDown";
    string arrowLeft = "arrowLeft";
    string arrowRight = "arrowRight";
    string triangleUp = "triangleUp";
    string triangleDown = "triangleDown";
    string triangleLeft = "triangleLeft";
    string triangleRight = "triangleRight";
}ErrorStyle;

class ErrorPlacement {
    public:

    string both = "both";
    string left = "left";
    string right = "right";
}ErrorPlacement;

class RuntimeFunction {
    public:

    string Constant = "Constant";
    string Execute = "Execute";
    string If = "If";
    string Switch = "Switch";
    string SwitchWithDefault = "SwitchWithDefault";
    string SwitchInteger = "SwitchInteger";
    string SwitchIntegerWithDefault = "SwitchIntegerWithDefault";
    string While = "While";
    string Add = "Add";
    string Subtract = "Subtract";
    string Multiply = "Multiply";
    string Divide = "Divide";
    string Mod = "Mod";
    string Power = "Power";
    string Log = "Log";
    string Equal = "Equal";
    string NotEqual = "NotEqual";
    string Greater = "Greater";
    string GreaterOr = "GreaterOr";
    string Less = "Less";
    string LessOr = "LessOr";
    string And = "And";
    string Or = "Or";
    string Not = "Not";
    string Abs = "Abs";
    string Sign = "Sign";
    string Min = "Min";
    string Max = "Max";
    string Ceil = "Ceil";
    string Floor = "Floor";
    string Round = "Round";
    string Frac = "Frac";
    string Trunc = "Trunc";
    string Degree = "Degree";
    string Radian = "Radian";
    string Sin = "Sin";
    string Cos = "Cos";
    string Tan = "Tan";
    string Sinh = "Sinh";
    string Cosh = "Cosh";
    string Tanh = "Tanh";
    string Arcsin = "Arcsin";
    string Arccos = "Arccos";
    string Arctan = "Arctan";
    string Arctan2 = "Arctan2";
    string Clamp = "Clamp";
    string Lerp = "Lerp";
    string LerpClamped = "LerpClamped";
    string Unlerp = "Unlerp";
    string UnlerpClamped = "UnlerpClamped";
    string Remap = "Remap";
    string RemapClamped = "RemapClamped";
    string Smoothstep = "Smoothstep";
    string Random = "Random";
    string RandomInteger = "RandomInteger";
    string Get = "Get";
    string GetShifted = "GetShifted";
    string Set = "Set";
    string SetShifted = "SetShifted";
    string Draw = "Draw";
    string DrawCurvedL = "DrawCurvedL";
    string DrawCurvedR = "DrawCurvedR";
    string DrawCurvedLR = "DrawCurvedLR";
    string DrawCurvedB = "DrawCurvedB";
    string DrawCurvedT = "DrawCurvedT";
    string DrawCurvedBT = "DrawCurvedBT";
    string Play = "Play";
    string PlayScheduled = "PlayScheduled";
    string Spawn = "Spawn";
    string SpawnParticleEffect = "SpawnParticleEffect";
    string MoveParticleEffect = "MoveParticleEffect";
    string DestroyParticleEffect = "DestroyParticleEffect";
    string HasSkinSprite = "HasSkinSprite";
    string HasEffectClip = "HasEffectClip";
    string HasParticleEffect = "HasParticleEffect";
    string Judge = "Judge";
    string JudgeSimple = "JudgeSimple";
    string EaseInSine = "EaseInSine";
    string EaseInQuad = "EaseInQuad";
    string EaseInCubic = "EaseInCubic";
    string EaseInQuart = "EaseInQuart";
    string EaseInQuint = "EaseInQuint";
    string EaseInExpo = "EaseInExpo";
    string EaseInCirc = "EaseInCirc";
    string EaseInBack = "EaseInBack";
    string EaseInElastic = "EaseInElastic";
    string EaseOutSine = "EaseOutSine";
    string EaseOutQuad = "EaseOutQuad";
    string EaseOutCubic = "EaseOutCubic";
    string EaseOutQuart = "EaseOutQuart";
    string EaseOutQuint = "EaseOutQuint";
    string EaseOutExpo = "EaseOutExpo";
    string EaseOutCirc = "EaseOutCirc";
    string EaseOutBack = "EaseOutBack";
    string EaseOutElastic = "EaseOutElastic";
    string EaseInOutSine = "EaseInOutSine";
    string EaseInOutQuad = "EaseInOutQuad";
    string EaseInOutCubic = "EaseInOutCubic";
    string EaseInOutQuart = "EaseInOutQuart";
    string EaseInOutQuint = "EaseInOutQuint";
    string EaseInOutExpo = "EaseInOutExpo";
    string EaseInOutCirc = "EaseInOutCirc";
    string EaseInOutBack = "EaseInOutBack";
    string EaseInOutElastic = "EaseInOutElastic";
    string EaseOutInSine = "EaseOutInSine";
    string EaseOutInQuad = "EaseOutInQuad";
    string EaseOutInCubic = "EaseOutInCubic";
    string EaseOutInQuart = "EaseOutInQuart";
    string EaseOutInQuint = "EaseOutInQuint";
    string EaseOutInExpo = "EaseOutInExpo";
    string EaseOutInCirc = "EaseOutInCirc";
    string EaseOutInBack = "EaseOutInBack";
    string EaseOutInElastic = "EaseOutInElastic";
    string IsDebug = "IsDebug";
    string DebugPause = "DebugPause";
    string DebugLog = "DebugLog";
    string JumpLoop = "JumpLoop";
    string Paint = "Paint";
    string PlayLooped = "PlayLooped";
    string PlayLoopedScheduled = "PlayLoopedScheduled";
    string StopLooped = "StopLooped";
    string StopLoopedScheduled = "StopLoopedScheduled";
    string BeatToBPM = "BeatToBPM";
    string BeatToStartingBeat = "BeatToStartingBeat";
    string BeatToStartingTime = "BeatToStartingTime";
    string BeatToTime = "BeatToTime";
    string Block = "Block";
    string Break = "Break";
    string Copy = "Copy";
    string DecrementPostPointed = "DecrementPostPointed";
    string DecrementPostShifted = "DecrementPostShifted";
    string DecrementPost = "DecrementPost";
    string DecrementPrePointed = "DecrementPrePointed";
    string DecrementPreShifted = "DecrementPreShifted";
    string DecrementPre = "DecrementPre";
    string DoWhile = "DoWhile";
    string Execute0 = "Execute0";
    string GetPointed = "GetPointed";
    string IncrementPostPointed = "IncrementPostPointed";
    string IncrementPostShifted = "IncrementPostShifted";
    string IncrementPost = "IncrementPost";
    string IncrementPrePointed = "IncrementPrePointed";
    string IncrementPreShifted = "IncrementPreShifted";
    string IncrementPre = "IncrementPre";
    string Negate = "Negate";
    string Rem = "Rem";
    string SetAddPointed = "SetAddPointed";
    string SetAddShifted = "SetAddShifted";
    string SetAdd = "SetAdd";
    string SetDividePointed = "SetDividePointed";
    string SetDivideShifted = "SetDivideShifted";
    string SetDivide = "SetDivide";
    string SetModPointed = "SetModPointed";
    string SetModShifted = "SetModShifted";
    string SetMod = "SetMod";
    string SetMultiplyPointed = "SetMultiplyPointed";
    string SetMultiplyShifted = "SetMultiplyShifted";
    string SetMultiply = "SetMultiply";
    string SetSubtractPointed = "SetSubtractPointed";
    string SetSubtractShifted = "SetSubtractShifted";
    string SetSubtract = "SetSubtract";
    string SetPointed = "SetPointed";
    string SetPowerPointed = "SetPowerPointed";
    string SetPowerShifted = "SetPowerShifted";
    string SetPower = "SetPower";
    string SetRemPointed = "SetRemPointed";
    string SetRemShifted = "SetRemShifted";
    string SetRem = "SetRem";
    string StackEnter = "StackEnter";
    string StackGetFramePointer = "StackGetFramePointer";
    string StackGetFrame = "StackGetFrame";
    string StackGetPointer = "StackGetPointer";
    string StackGet = "StackGet";
    string StackGrow = "StackGrow";
    string StackInit = "StackInit";
    string StackLeave = "StackLeave";
    string StackPop = "StackPop";
    string StackPush = "StackPush";
    string StackSetFramePointer = "StackSetFramePointer";
    string StackSetFrame = "StackSetFrame";
    string StackSetPointer = "StackSetPointer";
    string StackSet = "StackSet";
    string TimeToScaledTime = "TimeToScaledTime";
    string TimeToStartingScaledTime = "TimeToStartingScaledTime";
    string TimeToStartingTime = "TimeToStartingTime";
    string TimeToTimeScale = "TimeToTimeScale";
}RuntimeFunction;

#endif