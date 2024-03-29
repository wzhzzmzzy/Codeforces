# Codeforeces 自用刷题模板

## Features

1. VSC + CMake 一键编译运行，使用 C++ 17，支持 Clang / GNU C++
2. 使用 GoogleTest 运行单测
3. 支持通过 `freopen` 指定输入、输出文件

## Quick start

0. 安装 G++ 或者 Clang
1. Clone Repo
```shell
git clone https://github.com/google/googletest.git third_party/gtest
```
2. Clone GoogleTest 到 third_party/gtest 目录
```shell
git clone https://github.com/wzhzzmzzy/Codeforces.git
```
3. 创建 build 目录，构建
```shell
mkdir build
cd build
cmake ..
make
```
4. 运行单测
```shell
./tests/tests
```
5. 运行 main，参数为题目编号
```shell
./codeforces 1374C
```

## Usage

### VSCode 使用

1. 安装 CMake、CMake Tools 插件
2. 选择编译器 G++ 或者 Clang
3. 点击运行，选择 codeforces
4. 如需修改默认参数，可以在 `.vscode/settings.json` 中修改
5. 添加题目后运行

### 一键创建新题

```shell
python3 ./scripts/new_problem.py 123A
```

此脚本会自动创建：
- solutions 中的 cpp/hpp
- tests 中的 cpp
- samples 中的 txt
- 更新 solutions.hpp

**依然需要手动修改 main.cpp**

### 一键添加 STDOUT 单测

在任意单测 cpp 文件中，输入 `teststdout` 前缀，会自动触发预设的单测 Snippets

### 创建新题

1. 在 `src/solutions` 中创建新的 cpp 和 hpp 文件即可，建议使用题号作为名称。
    hpp 文件中需要包含 solve 和 main 函数。solve 函数用于单元测试，main 函数用于直接调用。
    cpp 文件需要使用 namespace 包裹，避免同名函数冲突，模板如下：
    ```cpp
    // 1A.cpp
    namespace CF_1A {
        int main() {
            return 0;
        }
    }
    // 1A.hpp
    namespace CF_1A {
        int main();
    }
    ```
2. 新添加的 hpp 文件需要在 `src/solutions.hpp` 中 include
3. 在 `src/main.cpp` 中添加 main 函数的调用即可：
    ```cpp
    if (problem_id == "1A") {
        return CF_1A::main();
    }
    ```

### 创建单测

1. 在 `tests/` 中创建单测文件
2. 如果需要劫持 stdin/stdout，可以仿照 1374C_test.cpp 中的 test_file，修改其中的samples文件即可：
```cpp
TEST(Case_1374C, test_file) {
    // 劫持 stdout
    testing::internal::CaptureStdout();
    // 劫持 stdin
    freopen("samples/1374C.txt", "r", stdin);
    // 读答案文件
    std::ifstream input_file("samples/1374C_ans.txt");
    std::string ans = std::string(
        std::istreambuf_iterator<char>(input_file),
        std::istreambuf_iterator<char>()
    );
    // 执行 main
    CF_1374C::main();
    // 获取 stdout 内容
    std::string output = testing::internal::GetCapturedStdout();
    // 对比答案是否正确，注意换行符可能导致测试不通过
    ASSERT_STREQ(output.c_str(), ans.c_str());
}
```

### 运行单测

如果只需要运行一个文件的单测，需要修改 `tests/CMakeLists.txt` 中的这一行：
```
# 把 1A_test.cpp 改成需要执行的
set(TESTS_SINGLE main.cpp 1A_test.cpp)
```