# 注意事项

## 对于库使用者

- 不可使用 `VarType VarName(Params);` 的方式初始化变量，请切换为使用 `VarType VarName = VarType(Params);`，否则会被识别为函数定义导致后期编译错误。
- 不可使用 `for (VarType : VarName)` 的方式遍历，请切换为使用 `for (VarTypeIterator it = VarName.begin(); it != VarName.end(); it++)`。
- 不建议使用 `(VarType)Var` 的方式强制转换变量类型，请切换为使用 `VarType(Var)`。
- 不建议在函数中间使用预处理指令，否则解释器会无法识别后续的指令导致编译错误或无法正常运行。
- 在函数命名时，如果与库函数重名，否则解释器可能会生成无法编译的代码。
- 不建议使用原生指针类型，否则解释器可能会生成无法编译的代码。
- 类/结构体的构造/析构/拷贝/移动函数定义前需加上 `Constructor/Destructor/Constructor/Constructor` 补全与正常函数定义相比缺少的返回值类型，否则解释器会将其识别为函数调用。
- 如果需要暂时禁用解释器功能，请使用 `DISABLE_INTERPRETER` 宏定义。
- 如果有需要在 IDE 里出现而不在编译时出现的代码，请使用 `COMPILE_RUNTIME` 宏定义。

- 禁用 `throw`！禁用 `throw`！禁用 `throw`！请使用 `SonolusAssert`！
- 如果需要禁用打包皮肤功能，请使用 `DISABLE_PACK_SKIN` 宏定义。
- 如果需要禁用打包音效功能，请使用 `DISABLE_PACK_EFFECT` 宏定义。

## 对于库开发者

- `mergeNodeContainer` 函数只返回 `FuncNode`，内部不会执行该 `FuncNode`，因此需要调用 `SonolusRun` 函数来执行该 `FuncNode`。