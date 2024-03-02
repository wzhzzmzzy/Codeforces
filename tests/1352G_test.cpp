#include <iostream>
#include <fstream>
#include "gtest/gtest.h"
#include "solutions/1352G.hpp"

TEST(Case_1352G, test1) {
    std::string ans1 = CF_1352G::solve(1);
    ASSERT_STREQ(ans1.c_str(), "-1");
}
