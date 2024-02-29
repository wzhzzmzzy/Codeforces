/**
 * https://codeforces.com/problemset/problem/1374/C
 */

namespace CF_1374C {

#include <stdio.h>
 
int solve(int len, const char* s) {
    int ans = 0;
    int left = 0;
    int right = 0;
    for (int i = 0; i < len; ++i) {
        if (s[i] == '(') {
            ++left;
        } else {
            ++right;
            if (left + ans < right) {
                ans++;
            }
        }
    }
    return ans;
}

int main() {
    int n; scanf("%d", &n);
    while (n) {
        int len; char s[51]; 
        scanf("%d", &len); 
        scanf("%s", s);
        int ans = solve(len, s);
        printf("%d\n", ans);
        n--;
    }
    return 0;
}

}