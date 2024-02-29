#include <iostream>
#include <fstream>
#include "gtest/gtest.h"
#include "solutions/1374C.hpp"

TEST(Case_1374C, test1) {
    int ans1 = CF_1374C::solve(2, ")(");
    ASSERT_EQ(ans1, 1);
    int ans2 = CF_1374C::solve(4, "()()");
    ASSERT_EQ(ans2, 0);
    int ans3 = CF_1374C::solve(8, "())()()(");
    ASSERT_EQ(ans3, 1);
    int ans4 = CF_1374C::solve(10, ")))((((())");
    ASSERT_EQ(ans4, 3);
}

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