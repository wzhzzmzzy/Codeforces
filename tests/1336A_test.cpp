#include <iostream>
#include <fstream>
#include "gtest/gtest.h"
#include "solutions/1336A.hpp"

TEST(Case_1336A, test_file) {
    testing::internal::CaptureStdout();
    freopen("samples/1336A.txt", "r", stdin);
    std::ifstream input_file("samples/1336A_ans.txt");
    std::string ans = std::string(
        std::istreambuf_iterator<char>(input_file),
        std::istreambuf_iterator<char>()
    );
    CF_1336A::main();
    std::string output = testing::internal::GetCapturedStdout();
    ASSERT_STREQ(output.c_str(), ans.c_str());
}
