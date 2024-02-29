#include <cstdio>
#include <string>
#include "solutions.hpp"

// #define LOCAL

int main(int argc, char *const argv[]) {
    if (argc == 0) {
        printf("Need Problem ID\n");
        return 1;
    }

    if (argc > 0) {
        std::string problem_id(argv[1]);
#ifdef LOCAL
        freopen("tests/1374C.txt", "r", stdin);
#endif
        if (problem_id == "1374C") return CF_1374C::main();
    }
    return 0;
}
