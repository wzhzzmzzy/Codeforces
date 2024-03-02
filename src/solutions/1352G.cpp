/**
 * https://codeforces.com/problemset/problem/1352/G
 */

#include <string>
#include <iostream>

namespace CF_1352G {

#include <stdio.h>

std::string prefix(int n) {
    std::string ans = "";
    for (int i = n % 2 == 0 ? 2 : 1; i <= n; i += 2) {
        ans += std::to_string(i);
        ans += " ";
    }
    return ans;
}

std::string suffix(int n) {
    if (n < 1) return "";
    std::string ans = "";
    for (int i = n; i >= 1; i -= 2) {
        ans += std::to_string(i);
        ans += " ";
    }
    return ans;
}

std::string solve(int n) {
    if (n <= 3) return "-1";
    std::string ans = prefix(n);
    ans += std::to_string(n - 3);
    ans += " ";
    ans += std::to_string(n - 1);
    ans += " ";
    ans += suffix(n - 5);
    return ans;
}

int main() {
    int n; scanf("%d\n", &n);
    while (n--) {
        int p; scanf("%d\n", &p);
        std::cout << solve(p) << std::endl;
    }
    return 0;
}

}
