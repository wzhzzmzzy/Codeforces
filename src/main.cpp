#include <stdio.h>
#include <iostream>
#include <string>
#include "solutions.hpp"

#define LOCAL

int main(int argc, char *const argv[]) {
    if (argc == 1) {
        std::cout << "Need Problem ID" << std::endl;
        return 1;
    }

    if (argc > 1) {
        std::string problem_id(argv[1]);
#ifdef LOCAL
        std::string sample_path = "samples/";
        sample_path += problem_id;
        freopen((sample_path+".txt").c_str(), "r", stdin);
        // freopen((sample_path+"_out.txt").c_str(), "w", stdout);
#endif
        if (problem_id == "1374C") {
            return CF_1374C::main();
        }
    }
    return 0;
}
