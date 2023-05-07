FuncNode Abs(FuncNode expr) {
    return FuncNode(EngineDataFunctionName_Abs, {expr});
}

FuncNode Add(vector<FuncNode> expr) {
    return FuncNode(EngineDataFunctionName_Add, expr);
}

FuncNode And(vector<FuncNode> expr) {
    return FuncNode(EngineDataFunctionName_And, expr);
}

FuncNode Arccos(FuncNode expr) {
    return FuncNode(EngineDataFunctionName_Arccos, {expr});
}

FuncNode Arcsin(FuncNode expr) {
    return FuncNode(EngineDataFunctionName_Arcsin, {expr});
}

FuncNode Arctan(FuncNode expr) {
    return FuncNode(EngineDataFunctionName_Arctan, {expr});
}

//
FuncNode Arctan2(FuncNode x, FuncNode y) {
    return FuncNode(EngineDataFunctionName_Arctan2, {y, x});
}

FuncNode Ceil(FuncNode expr) {
    return FuncNode(EngineDataFunctionName_Ceil, {expr});
}

FuncNode Clamp(FuncNode x, FuncNode a, FuncNode b) {
    return FuncNode(EngineDataFunctionName_Clamp, {x, a, b});
}

FuncNode Cos(FuncNode expr) {
    return FuncNode(EngineDataFunctionName_Cos, {expr});
}

FuncNode Cosh(FuncNode expr) {
    return FuncNode(EngineDataFunctionName_Cosh, {expr});
}

FuncNode Debuglog(FuncNode expr) {
    return FuncNode(EngineDataFunctionName_DebugLog, {expr});
}

FuncNode DebugPause() {
    return FuncNode(EngineDataFunctionName_DebugPause, {});
}

FuncNode Degree(FuncNode expr) {
    return FuncNode(EngineDataFunctionName_Degree, {expr});
}

FuncNode DestroyParticleEffect(FuncNode id) {
    return FuncNode(EngineDataFunctionName_DestroyParticleEffect, {id});
}

FuncNode Divide(vector<FuncNode> expr) {
    return FuncNode(EngineDataFunctionName_Divide, expr);
}

FuncNode Draw(FuncNode id, FuncNode x1, FuncNode y1, FuncNode x2, FuncNode y2, FuncNode x3, FuncNode y3, FuncNode x4, FuncNode y4, FuncNode z, FuncNode a) {
    return FuncNode(EngineDataFunctionName_Draw, {id, x1, y1, x2, y2, x3, y3, x4, y4, z, a});
}

FuncNode DrawCurvedB(FuncNode id, FuncNode x1, FuncNode y1, FuncNode x2, FuncNode y2, FuncNode x3, FuncNode y3, FuncNode x4, FuncNode y4, FuncNode z, FuncNode a, FuncNode n, FuncNode cxB, FuncNode cyB) {
    return FuncNode(EngineDataFunctionName_DrawCurvedB, {id, x1, y1, x2, y2, x3, y3, x4, y4, z, a, n, cxB, cyB});
}

FuncNode DrawCurvedBT(FuncNode id, FuncNode x1, FuncNode y1, FuncNode x2, FuncNode y2, FuncNode x3, FuncNode y3, FuncNode x4, FuncNode y4, FuncNode z, FuncNode a, FuncNode n, FuncNode cxB, FuncNode cyB, FuncNode cxT, FuncNode cyT) {
    return FuncNode(EngineDataFunctionName_DrawCurvedBT, {id, x1, y1, x2, y2, x3, y3, x4, y4, z, a, n, cxB, cyB, cxT, cyT});
}

FuncNode DrawCurvedL(FuncNode id, FuncNode x1, FuncNode y1, FuncNode x2, FuncNode y2, FuncNode x3, FuncNode y3, FuncNode x4, FuncNode y4, FuncNode z, FuncNode a, FuncNode n, FuncNode cxL, FuncNode cyL) {
    return FuncNode(EngineDataFunctionName_DrawCurvedL, {id, x1, y1, x2, y2, x3, y3, x4, y4, z, a, n, cxL, cyL});
}

FuncNode DrawCurvedLR(FuncNode id, FuncNode x1, FuncNode y1, FuncNode x2, FuncNode y2, FuncNode x3, FuncNode y3, FuncNode x4, FuncNode y4, FuncNode z, FuncNode a, FuncNode n, FuncNode cxL, FuncNode cyL, FuncNode cxR, FuncNode cyR) {
    return FuncNode(EngineDataFunctionName_DrawCurvedLR, {id, x1, y1, x2, y2, x3, y3, x4, y4, z, a, n, cxL, cyL, cxR, cyR});
}

FuncNode DrawCurvedR(FuncNode id, FuncNode x1, FuncNode y1, FuncNode x2, FuncNode y2, FuncNode x3, FuncNode y3, FuncNode x4, FuncNode y4, FuncNode z, FuncNode a, FuncNode n, FuncNode cxR, FuncNode cyR) {
    return FuncNode(EngineDataFunctionName_DrawCurvedR, {id, x1, y1, x2, y2, x3, y3, x4, y4, z, a, n, cxR, cyR});
}

FuncNode DrawCurvedT(FuncNode id, FuncNode x1, FuncNode y1, FuncNode x2, FuncNode y2, FuncNode x3, FuncNode y3, FuncNode x4, FuncNode y4, FuncNode z, FuncNode a, FuncNode n, FuncNode cxT, FuncNode cyT) {
    return FuncNode(EngineDataFunctionName_DrawCurvedT, {id, x1, y1, x2, y2, x3, y3, x4, y4, z, a, n, cxT, cyT});
}

FuncNode Ease(FuncNode x, EngineDataFunctionName easeType) {
    return FuncNode(easeType, {x});
}

FuncNode Equal(FuncNode a, FuncNode b) {
    return FuncNode(EngineDataFunctionName_Equal, {a, b});
}

FuncNode Execute(vector<FuncNode> expr) {
    return FuncNode(EngineDataFunctionName_Execute, expr);
}

FuncNode Floor(FuncNode expr) {
    return FuncNode(EngineDataFunctionName_Floor, {expr});
}

FuncNode Frac(FuncNode expr) {
    return FuncNode(EngineDataFunctionName_Frac, {expr});
}

FuncNode Get(FuncNode id, FuncNode i) {
    return FuncNode(EngineDataFunctionName_Get, {id, i});
}

FuncNode GetShifted(FuncNode id, FuncNode i, FuncNode d) {
    return FuncNode(EngineDataFunctionName_GetShifted, {id, i, d});
}

FuncNode Greater(FuncNode a, FuncNode b) {
    return FuncNode(EngineDataFunctionName_Greater, {a, b});
}

FuncNode GreaterOr(FuncNode a, FuncNode b) {
    return FuncNode(EngineDataFunctionName_GreaterOr, {a, b});
}

FuncNode HasEffectClip(FuncNode id) {
    return FuncNode(EngineDataFunctionName_HasEffectClip, {id});
}

FuncNode HasParticleEffect(FuncNode id) {
    return FuncNode(EngineDataFunctionName_HasParticleEffect, {id});
}

FuncNode HasSkinSprite(FuncNode id) {
    return FuncNode(EngineDataFunctionName_HasSkinSprite, {id});
}

FuncNode If(FuncNode cond, FuncNode trueExpr, FuncNode falseExpr) {
    return FuncNode(EngineDataFunctionName_If, {cond, trueExpr, falseExpr});
}

FuncNode IsDebug() {
    return FuncNode(EngineDataFunctionName_IsDebug, {});
}

FuncNode Judge(FuncNode target, FuncNode source, FuncNode min_1, FuncNode max_1, FuncNode min_2, FuncNode max_2, FuncNode min_3, FuncNode max_3) {
    return FuncNode(EngineDataFunctionName_Judge, {target, source, min_1, max_1, min_2, max_2, min_3, max_3});
}

FuncNode JudgeSimple(FuncNode target, FuncNode source, FuncNode max_1, FuncNode max_2, FuncNode max_3) {
    return FuncNode(EngineDataFunctionName_JudgeSimple, {target, source, max_1, max_2, max_3});
}

FuncNode JumpLoop(vector<FuncNode> branch) {
    return FuncNode(EngineDataFunctionName_JumpLoop, branch);
}

FuncNode Lerp(FuncNode a, FuncNode b, FuncNode x) {
    return FuncNode(EngineDataFunctionName_Lerp, {a, b, x});
}

FuncNode LerpClamped(FuncNode a, FuncNode b, FuncNode x) {
    return FuncNode(EngineDataFunctionName_LerpClamped, {a, b, x});
}

FuncNode Less(FuncNode a, FuncNode b) {
    return FuncNode(EngineDataFunctionName_Less, {a, b});
}

FuncNode LessOr(FuncNode a, FuncNode b) {
    return FuncNode(EngineDataFunctionName_LessOr, {a, b});
}

FuncNode Log(vector<FuncNode> expr) {
    return FuncNode(EngineDataFunctionName_Log, expr);
}

FuncNode Max(FuncNode a, FuncNode b) {
    return FuncNode(EngineDataFunctionName_Max, {a, b});
}

FuncNode Min(FuncNode a, FuncNode b) {
    return FuncNode(EngineDataFunctionName_Min, {a, b});
}

FuncNode Mod(vector<FuncNode> expr) {
    return FuncNode(EngineDataFunctionName_Mod, expr);
}

FuncNode MoveParticleEffect(FuncNode id, FuncNode x1, FuncNode y1, FuncNode x2, FuncNode y2, FuncNode x3, FuncNode y3, FuncNode x4, FuncNode y4) {
    return FuncNode(EngineDataFunctionName_MoveParticleEffect, {id, x1, y1, x2, y2, x3, y3, x4, y4});
}

FuncNode Multiply(vector<FuncNode> expr) {
    return FuncNode(EngineDataFunctionName_Multiply, expr);
}

FuncNode Not(FuncNode expr) {
    return FuncNode(EngineDataFunctionName_Not, {expr});
}

FuncNode NotEqual(FuncNode a, FuncNode b) {
    return FuncNode(EngineDataFunctionName_NotEqual, {a, b});
}

FuncNode Or(vector<FuncNode> expr) {
    return FuncNode(EngineDataFunctionName_Or, expr);
}

FuncNode Play(FuncNode id, FuncNode dist) {
    return FuncNode(EngineDataFunctionName_Play, {id, dist});
}

FuncNode PlayLooped(FuncNode id) {
    return FuncNode(EngineDataFunctionName_PlayLooped, {id});
}

FuncNode PlayLoopedScheduled(FuncNode id, FuncNode t) {
    return FuncNode(EngineDataFunctionName_PlayLoopedScheduled, {id, t});
}

//
FuncNode PlayScheduled(FuncNode id, FuncNode dist, FuncNode t) {
    return FuncNode(EngineDataFunctionName_PlayScheduled, {id, t, dist});
}

FuncNode Power(vector<FuncNode> expr) {
    return FuncNode(EngineDataFunctionName_Power, expr);
}

FuncNode Radian(FuncNode expr) {
    return FuncNode(EngineDataFunctionName_Radian, {expr});
}

FuncNode Random(FuncNode a, FuncNode b, FuncNode x) {
    return FuncNode(EngineDataFunctionName_Random, {a, b, x});
}

FuncNode RandomInteger(FuncNode a, FuncNode b, FuncNode x) {
    return FuncNode(EngineDataFunctionName_RandomInteger, {a, b, x});
}

FuncNode Remap(FuncNode a, FuncNode b, FuncNode c, FuncNode d, FuncNode expr) {
    return FuncNode(EngineDataFunctionName_Remap, {a, b, c, d, expr});
}

FuncNode Round(FuncNode expr) {
    return FuncNode(EngineDataFunctionName_Round, {expr});
}

FuncNode Set(FuncNode id, FuncNode i, FuncNode value) {
    return FuncNode(EngineDataFunctionName_Set, {id, i, value});
}

FuncNode SetShifted(FuncNode id, FuncNode i, FuncNode d, FuncNode value) {
    return FuncNode(EngineDataFunctionName_SetShifted, {id, i, d, value});
}

FuncNode Sign(FuncNode expr) {
    return FuncNode(EngineDataFunctionName_Sign, {expr});
}

FuncNode Sin(FuncNode expr) {
    return FuncNode(EngineDataFunctionName_Sin, {expr});
}

FuncNode Sinh(FuncNode expr) {
    return FuncNode(EngineDataFunctionName_Sinh, {expr});
}

FuncNode Smoothstep(FuncNode a, FuncNode b, FuncNode x) {
    return FuncNode(EngineDataFunctionName_Smoothstep, {a, b, x});
}

FuncNode Spawn(FuncNode id, FuncNode data) {
    return FuncNode(EngineDataFunctionName_Spawn, {id, data});
}

FuncNode SpawnParticleEffect(FuncNode id, FuncNode x1, FuncNode y1, FuncNode x2, FuncNode y2, FuncNode x3, FuncNode y3, FuncNode x4, FuncNode y4, FuncNode t, FuncNode loop) {
    return FuncNode(EngineDataFunctionName_SpawnParticleEffect, {id, x1, y1, x2, y2, x3, y3, x4, y4, t, loop});
}

FuncNode StopLooped(FuncNode id) {
    return FuncNode(EngineDataFunctionName_StopLooped, {id});
}

FuncNode StopLoopedScheduled(FuncNode id, FuncNode t) {
    return FuncNode(EngineDataFunctionName_StopLoopedScheduled, {id, t});
}

FuncNode Subtract(vector<FuncNode> expr) {
    return FuncNode(EngineDataFunctionName_Subtract, expr);
}

FuncNode Switch(FuncNode cond, vector<pair<FuncNode, FuncNode> > expr) {
    vector<FuncNode> args; args.push_back(cond);
    for (int i = 0 ; i < expr.size(); i++) args.push_back(expr[i].first), args.push_back(expr[i].second);
    return FuncNode(EngineDataFunctionName_Switch, args);
}

FuncNode SwitchWithDefault(FuncNode cond, vector<pair<FuncNode, FuncNode> > expr, FuncNode expr_def) {
    vector<FuncNode> args; args.push_back(cond);
    for (int i = 0 ; i < expr.size(); i++) args.push_back(expr[i].first), args.push_back(expr[i].second);
    args.push_back(expr_def);
    return FuncNode(EngineDataFunctionName_SwitchWithDefault, args);
}

FuncNode SwitchInteger(FuncNode cond, vector<FuncNode> expr) {
    expr.insert(expr.begin(), cond);
    return FuncNode(EngineDataFunctionName_SwitchInteger, expr);
}

FuncNode SwitchIntegerWithDefault(FuncNode cond, vector<FuncNode> expr, FuncNode expr_def) {
    expr.insert(expr.begin(), cond); expr.push_back(expr_def);
    return FuncNode(EngineDataFunctionName_SwitchIntegerWithDefault, expr);
}

FuncNode Tan(FuncNode expr) {
    return FuncNode(EngineDataFunctionName_Tan, {expr});
}

FuncNode Tanh(FuncNode expr) {
    return FuncNode(EngineDataFunctionName_Tanh, {expr});
}

FuncNode Trunc(FuncNode expr) {
    return FuncNode(EngineDataFunctionName_Trunc, {expr});
}

FuncNode Unlerp(FuncNode a, FuncNode b, FuncNode x) {
    return FuncNode(EngineDataFunctionName_Unlerp, {a, b, x});
}

FuncNode UnlerpClamped(FuncNode a, FuncNode b, FuncNode x) {
    return FuncNode(EngineDataFunctionName_UnlerpClamped, {a, b, x});
}

FuncNode While(FuncNode cond, FuncNode expr) {
    return FuncNode(EngineDataFunctionName_While, {cond, expr});
}