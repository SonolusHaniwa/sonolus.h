# Sonolus Engine Library in C++

# This project is unfinished!!!

下载依赖：

```bash
sudo apt install libjsoncpp-dev libssl-dev zliblg-dev -y
```

基础编译指令:

```bash
g++ main.cpp -omain -ljsoncpp -lssl -lcrypto -lz
```

编译选项: 

- `-DDISABLE_JSPREFER`: 禁用 NodeJS 代码偏好。(即禁用 `typedef FuncNode var;` 和 `typedef FuncNode let;` 以避免冲突问题)
- `-DDISABLE_REDEFINE`: 禁用 `FuncNode` 的运算符重载。(即禁用所有 `FuncNode operator * (FuncNode a, FuncNode b){}`)

Todo List:

- [x] 实现 `EngineData` 和 `EngineConfiguration` 基础结构。
- [x] 实现 `FuncNode` 的运算符重载功能。
- [x] 实现 `build` 功能。
- [ ] 预定义部分 `block` 指针 (7 / 19)。
- [ ] 以插件形式接入 [sonolus-server-cpp](https://github.com/SonolusHaniwa/sonolus-server-cpp)
- [ ] 完成英文文档。
- [ ] 完成 wiki 界面。