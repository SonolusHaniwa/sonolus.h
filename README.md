<p align="center"><img src="https://github.com/SonolusHaniwa/sonolus-server-cpp/assets/63852815/e7f00aea-cc1b-428b-8611-0c1844dcd15a"/></p>

<h1 align="center">Sonolus Engine Library in C++</h1>

使用 C++ 开发的一个 Sonolus 引擎开发库。

样例引擎地址: [World Dai Star: Dream's Stellarium](https://github.com/SonolusHaniwa/sonolus-sirius-engine), [Phigros](https://github.com/SonolusHaniwa/sonolus-phigros-engine)

## 链接

- [Sonolus Website](https://sonolus.com/)
- [Sonolus Wiki](https://wiki.sonolus.com/)
- [SonolusHaniwa Documents](https://docs.littleyang.me/sonolus.h/basic/1.%20install.html)

## 构建

### 下载依赖

```bash
sudo apt install libjsoncpp-dev libssl-dev zlib1g-dev libpng-dev libzip-dev -y
```

在主程序中直接引入 `sonolus.h` 即可。`main.cpp` 为示例程序。

### 编译

基础编译指令:

```bash
g++ main.cpp -omain -ljsoncpp -lssl -lcrypto -lz -lpng -lzip
```

**附加编译选项列表**

- `-Dplay`: 编译 EnginePlayData 和 EngineConfiguration
- `-Dtutorial`: 编译 EngineTutorialData 和 EngineConfiguration
- `-Dpreview`: 编译 EnginePreviewData 和 EngineConfiguration
- `-Dwatch`: 编译 EngineWatchData 和 EngineConfiguration
- `-DENABLE_TRACE`: 提供编译报错时的函数调用结构，需要 `cpptrace` 库支持

## Todo List

- [x] 实现 `EngineData` 和 `EngineConfiguration` 基础结构。
- [x] 实现 `FuncNode` 的运算符重载功能。
- [x] 实现 `build` 功能。
- [x] 预定义部分 `block` 指针。
- [x] 以插件形式接入 [sonolus-server-cpp](https://github.com/SonolusHaniwa/sonolus-server-cpp)
- [x] 实现简单的编译报错功能。
- [ ] 完成英文文档。
- [ ] 完成 wiki 界面。