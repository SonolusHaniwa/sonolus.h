FuncNode Abs(FuncNode value) {
    return FuncNode(RuntimeFunction_Abs, {value});
}

FuncNode Add(vector<FuncNode> value) {
    return FuncNode(RuntimeFunction_Add, value);
}

FuncNode And(vector<FuncNode> value) {
    return FuncNode(RuntimeFunction_And, value);
}

FuncNode Arccos(FuncNode value) {
    return FuncNode(RuntimeFunction_Arccos, {value});
}

FuncNode Arcsin(FuncNode value) {
    return FuncNode(RuntimeFunction_Arcsin, {value});
}

FuncNode Arctan(FuncNode value) {
    return FuncNode(RuntimeFunction_Arctan, {value});
}

//
FuncNode Arctan2(FuncNode x, FuncNode y) {
    return FuncNode(RuntimeFunction_Arctan2, {y, x});
}

FuncNode BeatToBPM(FuncNode beat) {
    return FuncNode(RuntimeFunction_BeatToBPM, {beat});
}

FuncNode BeatToStartingBeat(FuncNode beat) {
    return FuncNode(RuntimeFunction_BeatToStartingBeat, {beat});
}

FuncNode BeatToStartingTime(FuncNode beat) {
    return FuncNode(RuntimeFunction_BeatToStartingTime, {beat});
}

FuncNode BeatToTime(FuncNode beat) {
    return FuncNode(RuntimeFunction_BeatToTime, {beat});
}

FuncNode Block(FuncNode body) {
    return FuncNode(RuntimeFunction_Block, {body});
}

FuncNode Break(FuncNode count, FuncNode value) {
    return FuncNode(RuntimeFunction_Break, {count, value});
}

FuncNode Ceil(FuncNode value) {
    return FuncNode(RuntimeFunction_Ceil, {value});
}

FuncNode Clamp(FuncNode x, FuncNode a, FuncNode b) {
    return FuncNode(RuntimeFunction_Clamp, {x, a, b});
}

FuncNode Copy(FuncNode srcId, FuncNode srcIndex, FuncNode dstId, FuncNode dstIndex, FuncNode count) {
    return FuncNode(RuntimeFunction_Copy, {srcId, srcIndex, dstId, dstIndex, count});
} 

FuncNode Cos(FuncNode value) {
    return FuncNode(RuntimeFunction_Cos, {value});
}

FuncNode Cosh(FuncNode value) {
    return FuncNode(RuntimeFunction_Cosh, {value});
}

FuncNode Debuglog(FuncNode value) {
    return FuncNode(RuntimeFunction_DebugLog, {value});
}

FuncNode DecrementPostPointed(FuncNode id, FuncNode index, FuncNode offset) {
    return FuncNode(RuntimeFunction_DecrementPostPointed, {id, index, offset});
}

FuncNode DecrementPostShifted(FuncNode id, FuncNode x, FuncNode y, FuncNode s) {
    return FuncNode(RuntimeFunction_DecrementPostShifted, {id, x, y, s});
}

FuncNode DecrementPost(FuncNode id, FuncNode index) {
    return FuncNode(RuntimeFunction_DecrementPost, {id, index});
}

FuncNode DecrementPrePointed(FuncNode id, FuncNode index, FuncNode offset) {
    return FuncNode(RuntimeFunction_DecrementPrePointed, {id, index, offset});
}

FuncNode DecrementPreShifted(FuncNode id, FuncNode x, FuncNode y, FuncNode s) {
    return FuncNode(RuntimeFunction_DecrementPreShifted, {id, x, y, s});
}

FuncNode DecrementPre(FuncNode id, FuncNode index) {
    return FuncNode(RuntimeFunction_DecrementPre, {id, index});
}

FuncNode DebugPause() {
    return FuncNode(RuntimeFunction_DebugPause, {});
}

FuncNode Degree(FuncNode value) {
    return FuncNode(RuntimeFunction_Degree, {value});
}

FuncNode DestroyParticleEffect(FuncNode particleId) {
    return FuncNode(RuntimeFunction_DestroyParticleEffect, {particleId});
}

FuncNode Divide(vector<FuncNode> value) {
    return FuncNode(RuntimeFunction_Divide, value);
}

FuncNode DoWhile(FuncNode body, FuncNode test) {
    return FuncNode(RuntimeFunction_DoWhile, {body, test});
}

FuncNode Draw(FuncNode id, FuncNode x1, FuncNode y1, FuncNode x2, FuncNode y2, FuncNode x3, FuncNode y3, FuncNode x4, FuncNode y4, FuncNode z, FuncNode a) {
    return FuncNode(RuntimeFunction_Draw, {id, x1, y1, x2, y2, x3, y3, x4, y4, z, a});
}

FuncNode DrawCurvedB(FuncNode id, FuncNode x1, FuncNode y1, FuncNode x2, FuncNode y2, FuncNode x3, FuncNode y3, FuncNode x4, FuncNode y4, FuncNode z, FuncNode a, FuncNode n, FuncNode p, FuncNode q) {
    return FuncNode(RuntimeFunction_DrawCurvedB, {id, x1, y1, x2, y2, x3, y3, x4, y4, z, a, n, p, q});
}

FuncNode DrawCurvedBT(FuncNode id, FuncNode x1, FuncNode y1, FuncNode x2, FuncNode y2, FuncNode x3, FuncNode y3, FuncNode x4, FuncNode y4, FuncNode z, FuncNode a, FuncNode n, FuncNode p1, FuncNode q1, FuncNode p2, FuncNode q2) {
    return FuncNode(RuntimeFunction_DrawCurvedBT, {id, x1, y1, x2, y2, x3, y3, x4, y4, z, a, n, p1, q1, p2, q2});
}

FuncNode DrawCurvedL(FuncNode id, FuncNode x1, FuncNode y1, FuncNode x2, FuncNode y2, FuncNode x3, FuncNode y3, FuncNode x4, FuncNode y4, FuncNode z, FuncNode a, FuncNode n, FuncNode p, FuncNode q) {
    return FuncNode(RuntimeFunction_DrawCurvedL, {id, x1, y1, x2, y2, x3, y3, x4, y4, z, a, n, p, q});
}

FuncNode DrawCurvedLR(FuncNode id, FuncNode x1, FuncNode y1, FuncNode x2, FuncNode y2, FuncNode x3, FuncNode y3, FuncNode x4, FuncNode y4, FuncNode z, FuncNode a, FuncNode n, FuncNode p1, FuncNode q1, FuncNode p2, FuncNode q2) {
    return FuncNode(RuntimeFunction_DrawCurvedLR, {id, x1, y1, x2, y2, x3, y3, x4, y4, z, a, n, p1, q1, p2, q2});
}

FuncNode DrawCurvedR(FuncNode id, FuncNode x1, FuncNode y1, FuncNode x2, FuncNode y2, FuncNode x3, FuncNode y3, FuncNode x4, FuncNode y4, FuncNode z, FuncNode a, FuncNode n, FuncNode p, FuncNode q) {
    return FuncNode(RuntimeFunction_DrawCurvedR, {id, x1, y1, x2, y2, x3, y3, x4, y4, z, a, n, p, q});
}

FuncNode DrawCurvedT(FuncNode id, FuncNode x1, FuncNode y1, FuncNode x2, FuncNode y2, FuncNode x3, FuncNode y3, FuncNode x4, FuncNode y4, FuncNode z, FuncNode a, FuncNode n, FuncNode p, FuncNode q) {
    return FuncNode(RuntimeFunction_DrawCurvedT, {id, x1, y1, x2, y2, x3, y3, x4, y4, z, a, n, p, q});
}

FuncNode Ease(FuncNode value, RuntimeFunction easeType) {
    return FuncNode(easeType, {value});
}

FuncNode Equal(FuncNode lhs, FuncNode rhs) {
    return FuncNode(RuntimeFunction_Equal, {lhs, rhs});
}

FuncNode Execute(vector<FuncNode> value) {
    return FuncNode(RuntimeFunction_Execute, value);
}

FuncNode Execute0(vector<FuncNode> value) {
    return FuncNode(RuntimeFunction_Execute0, value);
}

FuncNode Floor(FuncNode value) {
    return FuncNode(RuntimeFunction_Floor, {value});
}

FuncNode Frac(FuncNode value) {
    return FuncNode(RuntimeFunction_Frac, {value});
}

FuncNode Get(FuncNode id, FuncNode index) {
    return FuncNode(RuntimeFunction_Get, {id, index});
}

FuncNode GetPointed(FuncNode id, FuncNode index, FuncNode offset) {
    return FuncNode(RuntimeFunction_GetPointed, {id, index, offset});
}

FuncNode GetShifted(FuncNode id, FuncNode x, FuncNode y, FuncNode s) {
    return FuncNode(RuntimeFunction_GetShifted, {id, x, y, s});
}

FuncNode Greater(FuncNode lhs, FuncNode rhs) {
    return FuncNode(RuntimeFunction_Greater, {lhs, rhs});
}

FuncNode GreaterOr(FuncNode lhs, FuncNode rhs) {
    return FuncNode(RuntimeFunction_GreaterOr, {lhs, rhs});
}

FuncNode HasEffectClip(FuncNode id) {
    return FuncNode(RuntimeFunction_HasEffectClip, {id});
}

FuncNode HasParticleEffect(FuncNode id) {
    return FuncNode(RuntimeFunction_HasParticleEffect, {id});
}

FuncNode HasSkinSprite(FuncNode id) {
    return FuncNode(RuntimeFunction_HasSkinSprite, {id});
}

FuncNode If(FuncNode test, FuncNode consequent, FuncNode alternate) {
    return FuncNode(RuntimeFunction_If, {test, consequent, alternate});
}

FuncNode IncrementPostPointed(FuncNode id, FuncNode index, FuncNode offset) {
    return FuncNode(RuntimeFunction_IncrementPostPointed, {id, index, offset});
}

FuncNode IncrementPostShifted(FuncNode id, FuncNode x, FuncNode y, FuncNode s) {
    return FuncNode(RuntimeFunction_IncrementPostShifted, {id, x, y, s});
}

FuncNode IncrementPost(FuncNode id, FuncNode index) {
    return FuncNode(RuntimeFunction_IncrementPost, {id, index});
}

FuncNode IncrementPrePointed(FuncNode id, FuncNode index, FuncNode offset) {
    return FuncNode(RuntimeFunction_IncrementPrePointed, {id, index, offset});
}

FuncNode IncrementPreShifted(FuncNode id, FuncNode x, FuncNode y, FuncNode s) {
    return FuncNode(RuntimeFunction_IncrementPreShifted, {id, x, y, s});
}

FuncNode IncrementPre(FuncNode id, FuncNode index) {
    return FuncNode(RuntimeFunction_IncrementPre, {id, index});
}

/*
FuncNode IsDebug() {
    return FuncNode(RuntimeFunction_IsDebug, {});
}
*/

FuncNode Judge(FuncNode target, FuncNode source, FuncNode minPerfect, FuncNode maxPerfect, FuncNode minGreat, FuncNode maxGreat, FuncNode minGood, FuncNode maxGood) {
    return FuncNode(RuntimeFunction_Judge, {target, source, minPerfect, maxPerfect, minGreat, maxGreat, minGood, maxGood});
}

FuncNode JudgeSimple(FuncNode target, FuncNode source, FuncNode maxPerfect, FuncNode maxGreat, FuncNode maxGood) {
    return FuncNode(RuntimeFunction_JudgeSimple, {target, source, maxPerfect, maxGreat, maxGood});
}

FuncNode JumpLoop(vector<FuncNode> branch) {
    return FuncNode(RuntimeFunction_JumpLoop, branch);
}

FuncNode Lerp(FuncNode x, FuncNode y, FuncNode s) {
    return FuncNode(RuntimeFunction_Lerp, {x, y, s});
}

FuncNode LerpClamped(FuncNode x, FuncNode y, FuncNode s) {
    return FuncNode(RuntimeFunction_LerpClamped, {x, y, s});
}

FuncNode Less(FuncNode lhs, FuncNode rhs) {
    return FuncNode(RuntimeFunction_Less, {lhs, rhs});
}

FuncNode LessOr(FuncNode lhs, FuncNode rhs) {
    return FuncNode(RuntimeFunction_LessOr, {lhs, rhs});
}

FuncNode Log(vector<FuncNode> value) {
    return FuncNode(RuntimeFunction_Log, value);
}

FuncNode Max(FuncNode x, FuncNode y) {
    return FuncNode(RuntimeFunction_Max, {x, y});
}

FuncNode Min(FuncNode x, FuncNode y) {
    return FuncNode(RuntimeFunction_Min, {x, y});
}

FuncNode Mod(vector<FuncNode> value) {
    return FuncNode(RuntimeFunction_Mod, value);
}

FuncNode MoveParticleEffect(FuncNode particleId, FuncNode x1, FuncNode y1, FuncNode x2, FuncNode y2, FuncNode x3, FuncNode y3, FuncNode x4, FuncNode y4) {
    return FuncNode(RuntimeFunction_MoveParticleEffect, {particleId, x1, y1, x2, y2, x3, y3, x4, y4});
}

FuncNode Multiply(vector<FuncNode> value) {
    return FuncNode(RuntimeFunction_Multiply, value);
}

FuncNode Negate(FuncNode value) {
    return FuncNode(RuntimeFunction_Negate, {value});
}

FuncNode Not(FuncNode value) {
    return FuncNode(RuntimeFunction_Not, {value});
}

FuncNode NotEqual(FuncNode lhs, FuncNode rhs) {
    return FuncNode(RuntimeFunction_NotEqual, {lhs, rhs});
}

FuncNode Or(vector<FuncNode> value) {
    return FuncNode(RuntimeFunction_Or, value);
}

FuncNode Play(FuncNode id, FuncNode distance) {
    return FuncNode(RuntimeFunction_Play, {id, distance});
}

FuncNode PlayLooped(FuncNode id) {
    return FuncNode(RuntimeFunction_PlayLooped, {id});
}

FuncNode PlayLoopedScheduled(FuncNode id, FuncNode startTime) {
    return FuncNode(RuntimeFunction_PlayLoopedScheduled, {id, startTime});
}

//
FuncNode PlayScheduled(FuncNode id, FuncNode distance, FuncNode time) {
    return FuncNode(RuntimeFunction_PlayScheduled, {id, time, distance});
}

FuncNode Power(vector<FuncNode> value) {
    return FuncNode(RuntimeFunction_Power, value);
}

FuncNode Radian(FuncNode value) {
    return FuncNode(RuntimeFunction_Radian, {value});
}

FuncNode Random(FuncNode min, FuncNode max) {
    return FuncNode(RuntimeFunction_Random, {min, max});
}

FuncNode RandomInteger(FuncNode min, FuncNode max) {
    return FuncNode(RuntimeFunction_RandomInteger, {min, max});
}

FuncNode Rem(vector<FuncNode> value) {
    return FuncNode(RuntimeFunction_Rem, value);
}

FuncNode Remap(FuncNode a, FuncNode b, FuncNode c, FuncNode d, FuncNode value) {
    return FuncNode(RuntimeFunction_Remap, {a, b, c, d, value});
}

FuncNode Round(FuncNode value) {
    return FuncNode(RuntimeFunction_Round, {value});
}

FuncNode Set(FuncNode id, FuncNode index, FuncNode value) {
    return FuncNode(RuntimeFunction_Set, {id, index, value});
}

FuncNode SetShifted(FuncNode id, FuncNode x, FuncNode y, FuncNode s, FuncNode value) {
    return FuncNode(RuntimeFunction_SetShifted, {id, x, y, s, value});
}

FuncNode SetAddPointed(FuncNode id, FuncNode index, FuncNode offset, FuncNode value) {
    return FuncNode(RuntimeFunction_SetAddPointed, {id, index, offset, value});
}

FuncNode SetAddShifted(FuncNode id, FuncNode x, FuncNode y, FuncNode s, FuncNode value) {
    return FuncNode(RuntimeFunction_SetAddShifted, {id, x, y, s, value});
}

FuncNode SetAdd(FuncNode id, FuncNode index, FuncNode value) {
    return FuncNode(RuntimeFunction_SetAdd, {id, index, value});
}

FuncNode SetDividePointed(FuncNode id, FuncNode index, FuncNode offset, FuncNode value) {
    return FuncNode(RuntimeFunction_SetDividePointed, {id, index, offset, value});
}

FuncNode SetDivideShifted(FuncNode id, FuncNode x, FuncNode y, FuncNode s, FuncNode value) {
    return FuncNode(RuntimeFunction_SetDivideShifted, {id, x, y, s, value});
}

FuncNode SetDivide(FuncNode id, FuncNode index, FuncNode value) {
    return FuncNode(RuntimeFunction_SetDivide, {id, index, value});
}

FuncNode SetModPointed(FuncNode id, FuncNode index, FuncNode offset, FuncNode value) {
    return FuncNode(RuntimeFunction_SetModPointed, {id, index, offset, value});
}

FuncNode SetModShifted(FuncNode id, FuncNode x, FuncNode y, FuncNode s, FuncNode value) {
    return FuncNode(RuntimeFunction_SetModShifted, {id, x, y, s, value});
}

FuncNode SetMod(FuncNode id, FuncNode index, FuncNode value) {
    return FuncNode(RuntimeFunction_SetMod, {id, index, value});
}

FuncNode SetMultiplyPointed(FuncNode id, FuncNode index, FuncNode offset, FuncNode value) {
    return FuncNode(RuntimeFunction_SetMultiplyPointed, {id, index, offset, value});
}

FuncNode SetMultiplyShifted(FuncNode id, FuncNode x, FuncNode y, FuncNode s, FuncNode value) {
    return FuncNode(RuntimeFunction_SetMultiplyShifted, {id, x, y, s, value});
}

FuncNode SetMultiply(FuncNode id, FuncNode index, FuncNode value) {
    return FuncNode(RuntimeFunction_SetMultiply, {id, index, value});
}

FuncNode SetPointed(FuncNode id, FuncNode index, FuncNode offset, FuncNode value) {
    return FuncNode(RuntimeFunction_SetPointed, {id, index, offset, value});
}

FuncNode SetPowerPointed(FuncNode id, FuncNode index, FuncNode offset, FuncNode value) {
    return FuncNode(RuntimeFunction_SetPowerPointed, {id, index, offset, value});
}

FuncNode SetPowerShifted(FuncNode id, FuncNode x, FuncNode y, FuncNode s, FuncNode value) {
    return FuncNode(RuntimeFunction_SetPowerShifted, {id, x, y, s, value});
}

FuncNode SetPower(FuncNode id, FuncNode index, FuncNode value) {
    return FuncNode(RuntimeFunction_SetPower, {id, index, value});
}

FuncNode SetRemPointed(FuncNode id, FuncNode index, FuncNode offset, FuncNode value) {
    return FuncNode(RuntimeFunction_SetRemPointed, {id, index, offset, value});
}

FuncNode SetRemShifted(FuncNode id, FuncNode x, FuncNode y, FuncNode s, FuncNode value) {
    return FuncNode(RuntimeFunction_SetRemShifted, {id, x, y, s, value});
}

FuncNode SetRem(FuncNode id, FuncNode index, FuncNode value) {
    return FuncNode(RuntimeFunction_SetRem, {id, index, value});
}

FuncNode SetSubtractPointed(FuncNode id, FuncNode index, FuncNode offset, FuncNode value) {
    return FuncNode(RuntimeFunction_SetSubtractPointed, {id, index, offset, value});
}

FuncNode SetSubtractShifted(FuncNode id, FuncNode x, FuncNode y, FuncNode s, FuncNode value) {
    return FuncNode(RuntimeFunction_SetSubtractShifted, {id, x, y, s, value});
}

FuncNode SetSubtract(FuncNode id, FuncNode index, FuncNode value) {
    return FuncNode(RuntimeFunction_SetSubtract, {id, index, value});
}

FuncNode Sign(FuncNode value) {
    return FuncNode(RuntimeFunction_Sign, {value});
}

FuncNode Sin(FuncNode value) {
    return FuncNode(RuntimeFunction_Sin, {value});
}

FuncNode Sinh(FuncNode value) {
    return FuncNode(RuntimeFunction_Sinh, {value});
}

/*
FuncNode Smoothstep(FuncNode a, FuncNode b, FuncNode x) {
    return FuncNode(RuntimeFunction_Smoothstep, {a, b, x});
}
*/

FuncNode Spawn(FuncNode id, FuncNode data) {
    return FuncNode(RuntimeFunction_Spawn, {id, data});
}

FuncNode SpawnParticleEffect(FuncNode id, FuncNode x1, FuncNode y1, FuncNode x2, FuncNode y2, FuncNode x3, FuncNode y3, FuncNode x4, FuncNode y4, FuncNode duration, FuncNode isLooped) {
    return FuncNode(RuntimeFunction_SpawnParticleEffect, {id, x1, y1, x2, y2, x3, y3, x4, y4, duration, isLooped});
}

FuncNode StackEnter(FuncNode size) {
    return FuncNode(RuntimeFunction_StackEnter, {size});
}

FuncNode StackGetFramePointer() {
    return FuncNode(RuntimeFunction_StackGetFramePointer, {});
}

FuncNode StackGetFrame(FuncNode offset) {
    return FuncNode(RuntimeFunction_StackGetFrame, {offset});
}

FuncNode StackGetPointer() {
    return FuncNode(RuntimeFunction_StackGetPointer, {});
}

FuncNode StackGet(FuncNode offset) {
    return FuncNode(RuntimeFunction_StackGet, {offset});
}

FuncNode StackGrow(FuncNode size) {
    return FuncNode(RuntimeFunction_StackGrow, {size});
}

FuncNode StackInit() {
    return FuncNode(RuntimeFunction_StackInit, {});
}

FuncNode StackLeave() {
    return FuncNode(RuntimeFunction_StackLeave, {});
}

FuncNode StackPop() {
    return FuncNode(RuntimeFunction_StackPop, {});
}

FuncNode StackPush(FuncNode value) {
    return FuncNode(RuntimeFunction_StackPush, {value});
}

FuncNode StackSetFramePointer(FuncNode value) {
    return FuncNode(RuntimeFunction_StackSetFramePointer, {value});
}

FuncNode StackSetFrame(FuncNode offset, FuncNode index) {
    return FuncNode(RuntimeFunction_StackSetFrame, {offset, index});
}

FuncNode StackSetPointer(FuncNode value) {
    return FuncNode(RuntimeFunction_StackSetPointer, {value});
}

FuncNode StackSet(FuncNode offset, FuncNode value) {
    return FuncNode(RuntimeFunction_StackSet, {offset, value});
}

FuncNode StopLooped(FuncNode loopId) {
    return FuncNode(RuntimeFunction_StopLooped, {loopId});
}

FuncNode StopLoopedScheduled(FuncNode loopId, FuncNode endTime) {
    return FuncNode(RuntimeFunction_StopLoopedScheduled, {loopId, endTime});
}

FuncNode Subtract(vector<FuncNode> value) {
    return FuncNode(RuntimeFunction_Subtract, value);
}

FuncNode Switch(FuncNode discriminant, vector<pair<FuncNode, FuncNode> > consequent) {
    vector<FuncNode> args; args.push_back(discriminant);
    for (int i = 0 ; i < consequent.size(); i++) args.push_back(consequent[i].first), args.push_back(consequent[i].second);
    return FuncNode(RuntimeFunction_Switch, args);
}

FuncNode SwitchWithDefault(FuncNode discriminant, vector<pair<FuncNode, FuncNode> > consequent, FuncNode consequent_def) {
    vector<FuncNode> args; args.push_back(discriminant);
    for (int i = 0 ; i < consequent.size(); i++) args.push_back(consequent[i].first), args.push_back(consequent[i].second);
    args.push_back(consequent_def);
    return FuncNode(RuntimeFunction_SwitchWithDefault, args);
}

FuncNode SwitchInteger(FuncNode discriminant, vector<FuncNode> consequent) {
    consequent.insert(consequent.begin(), discriminant);
    return FuncNode(RuntimeFunction_SwitchInteger, consequent);
}

FuncNode SwitchIntegerWithDefault(FuncNode discriminant, vector<FuncNode> consequent, FuncNode consequent_def) {
    consequent.insert(consequent.begin(), discriminant); consequent.push_back(consequent_def);
    return FuncNode(RuntimeFunction_SwitchIntegerWithDefault, consequent);
}

FuncNode Tan(FuncNode value) {
    return FuncNode(RuntimeFunction_Tan, {value});
}

FuncNode Tanh(FuncNode value) {
    return FuncNode(RuntimeFunction_Tanh, {value});
}

FuncNode TimeToScaledTime(FuncNode time) {
    return FuncNode(RuntimeFunction_TimeToScaledTime, {time});
}

FuncNode TimeToStartingScaledTime(FuncNode time) {
    return FuncNode(RuntimeFunction_TimeToStartingScaledTime, {time});
}

FuncNode TimeToStartingTime(FuncNode time) {
    return FuncNode(RuntimeFunction_TimeToStartingTime, {time});
}

FuncNode TimeToTimeScale(FuncNode time) {
    return FuncNode(RuntimeFunction_TimeToTimeScale, {time});
}

FuncNode Trunc(FuncNode value) {
    return FuncNode(RuntimeFunction_Trunc, {value});
}

FuncNode Unlerp(FuncNode a, FuncNode b, FuncNode x) {
    return FuncNode(RuntimeFunction_Unlerp, {a, b, x});
}

FuncNode UnlerpClamped(FuncNode a, FuncNode b, FuncNode x) {
    return FuncNode(RuntimeFunction_UnlerpClamped, {a, b, x});
}

FuncNode While(FuncNode test, FuncNode body) {
    return FuncNode(RuntimeFunction_While, {test, body});
}