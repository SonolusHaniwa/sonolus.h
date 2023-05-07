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

`-DDISABLE_JSPREFER`: 禁用 NodeJS 代码偏好。(即禁用 `typedef FuncNode var;` 和 `typedef FuncNode let;` 以避免冲突问题)
`-DDISABLE_REDEFINE`: 禁用 `FuncNode` 的运算符重载。(即禁用所有 `FuncNode operator * (FuncNode a, FuncNode b){}`);