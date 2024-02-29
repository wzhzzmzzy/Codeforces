#include <iostream>
#include <fstream>
#include "gtest/gtest.h"
#include "solutions/1366A.hpp"

TEST(Case_1366A, test1) {
    int ans1 = CF_1366A::solve(2, 1);
    ASSERT_EQ(ans1, 1);
}
