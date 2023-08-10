<p align="center"><img src="http://pic.littleyang.ml/sonolus-server-screenshot/favicon.png"/></p>

<h1 align="center">Sonolus Engine Library in C++</h1>

使用 C++ 开发的一个 Sonolus 引擎开发库。

目前该项目仅处于开发完成状态，并未进行完全测试，不保证生成出的文件能够正常使用。

测试引擎地址: https://github.com/SonolusHaniwa/sonolus-hwpl-engine/tree/dev

## 链接

- [Sonolus Website](https://sonolus.com/)
- [Sonolus Wiki](https://wiki.sonolus.com/)

## 构建

### 下载依赖

```bash
sudo apt install libjsoncpp-dev libssl-dev zlib1g-dev -y
```

在主程序中直接引入 `sonolus.h` 即可。`main.cpp` 为示例程序。

### 编译

基础编译指令:

```bash
g++ main.cpp -omain -ljsoncpp -lssl -lcrypto -lz
```

**附加编译选项列表**

- `-DDISABLE_JSPREFER`: 禁用 NodeJS 代码偏好。(即禁用 `typedef FuncNode var;` 和 `typedef FuncNode let;` 以避免冲突问题)
- `-DDISABLE_REDEFINE`: 禁用 `FuncNode` 的运算符重载。(即禁用所有 `FuncNode operator * (FuncNode a, FuncNode b){}`)
- `-Dplay`: 编译 EnginePlayData 和 EngineConfiguration
- `-Dtutorial`: 编译 EngineTutorialData 和 EngineConfiguration

## Todo List

- [x] 实现 `EngineData` 和 `EngineConfiguration` 基础结构。
- [x] 实现 `FuncNode` 的运算符重载功能。
- [x] 实现 `build` 功能。
- [x] 预定义部分 `block` 指针。
- [x] 以插件形式接入 [sonolus-server-cpp](https://github.com/SonolusHaniwa/sonolus-server-cpp)
- [ ] 完成英文文档。
- [ ] 完成 wiki 界面。
- [ ] 实现简单的编译报错功能。

## 更新日志

### v1.1.0 for Sonolus 0.7.2 2023.8.9

1. 新增对 TutorialData 的支持
2. 新增 IF/ELSE/FOR 宏定义
3. 修改整体架构

### v1.0.0-alpha for Sonolus 0.7.0 2023.6.17

所有基本结构体已全部完工，正在进行初步测试中。

具体修改参照 https://github.com/Sonolus/wiki-engine-specs/pull/7/files

### v1.0.0-alpha for Sonolus 0.6.5 2023.5.20

🎁 520 特供 💝

所有基本结构体已全部完工，正在进行初步测试中。

1. 实现 `EngineData` 和 `EngineConfiguration` 基础结构。
2. 实现 `FuncNode` 的运算符重载功能。
3. 实现 `build` 功能。
4. 预定义部分 `block` 指针，共 18 个。
