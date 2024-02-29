/**
 * https://codeforces.com/problemset/problem/1366/A
 */

namespace CF_1366A {

#include <stdio.h>
 
int solve(int a, int b) {
    if (a < b) {
        int t = a;
        a = b;
        b = t;
    }

    if (a >= 2 * b) {
        return b;
    }
    if (a == b) {
        return (a + b) / 3;
    }
    int ans = a / 2;
    int max_b = b - ans;
    int min_a = a - ans * 2;
    if (max_b >= 2 && min_a == 1) {
        ans += 1;
        max_b -= 2;
        min_a -= 1;
    }
    if (max_b >=2) {
        ans += max_b / 3;
    }
    return ans;
}

int main() {
    int n; scanf("%d", &n);
    while (n) {
        int a,b;
        scanf("%d %d", &a, &b); 
        int ans = solve(a, b);
        printf("%d\n", ans);
        n--;
    }
    return 0;
}

}