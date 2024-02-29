from os import path
import sys

if len(sys.argv) < 2:
    print('Usage: python3 new_problem.py [problem_id]')
    exit(1)

problem_id = sys.argv[1]
cpp_template = f"""/**
 * https://codeforces.com/problemset/problem/{problem_id[:-1]}/{problem_id[-1]}
 */

namespace CF_{problem_id} {{

#include <stdio.h>

int solve(int a, int b) {{
    int ans = a + b;
    return ans;
}}

int main() {{
    return 0;
}}

}}
"""

hpp_template = f"""namespace CF_{problem_id} {{
    int solve(int a, int b);
    int main();
}}
"""

test_template = f"""#include <iostream>
#include <fstream>
#include "gtest/gtest.h"
#include "solutions/{problem_id}.hpp"

TEST(Case_{problem_id}, test1) {{
    int ans1 = CF_{problem_id}::solve(1, 2);
    ASSERT_EQ(ans1, 3);
}}
"""

git_dir = path.abspath(path.join(path.abspath(__file__), '../..'))
src_dir = path.join(git_dir, 'src')
solution_dir = path.join(src_dir, 'solutions')
test_dir = path.join(git_dir, 'tests')
sample_dir = path.join(git_dir, 'samples')
with open(path.join(solution_dir, f'{problem_id}.cpp'), 'w') as f:
    f.write(cpp_template)
with open(path.join(solution_dir, f'{problem_id}.hpp'), 'w') as f:
    f.write(hpp_template)
with open(path.join(src_dir, 'solutions.hpp'), 'a') as f:
    f.write(f"\n#include \"solutions/{problem_id}.hpp\"")
with open(path.join(test_dir, f'{problem_id}_test.cpp'), 'w') as f:
    f.write(test_template)
with open(path.join(sample_dir, f'{problem_id}.txt'), 'w') as f:
    f.write("")