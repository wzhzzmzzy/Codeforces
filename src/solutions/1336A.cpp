/**
 * https://codeforces.com/problemset/problem/1336/A
 */

#include <map>
#include <queue>
#include <iostream>
#include <stdio.h>

namespace CF_1336A {

#define MAX_N 200020
#define LL long long

std::map<int, std::vector<int>> mp;
std::map<int, int> mp_dis;
std::map<int, int> mp_son;
 
// src, distination_num, distance
using dis = std::tuple<int, int, int>;
struct cmp {
    bool operator()(const dis l, const dis r) const { 
        auto l1 = std::get<1>(l);
        auto r1 = std::get<1>(r);
        auto l2 = std::get<2>(l);
        auto r2 = std::get<2>(r);
        auto happyl = l2 - l1 + 1;
        auto happyr = r2 - r1 + 1;
        if (happyl != happyr) {
            return happyl < happyr;
        }
        return l1 > r1;
        // if (l1 != r1) return l1 > r1;
        // return happyl < happyr;
    }
};
std::priority_queue<
    dis, 
    std::vector<dis>,
    cmp
> dis_queue;
 
void dfs_dis(int src, int dis, int fa) {
    mp_dis[src] = dis;
    mp_son[src] = 1;
    for (int i: mp[src]) {
        if (i == fa) continue;
        dfs_dis(i, dis + 1, src);
        mp_son[src] += mp_son[i];
    }
}
 
LL solve(int n, int k, int road[MAX_N][2]) {
    for (int i = 0; i < n-1; i++) {
        mp[road[i][0]].push_back(road[i][1]);
        mp[road[i][1]].push_back(road[i][0]);
    }
    dfs_dis(1, 0, -1);
    for (int i = 1; i <= n; i++) {
        dis_queue.push(std::make_tuple(i, mp_son[i], mp_dis[i]));
    }

    LL ans = 0;
    for (int i = 0; i < k; i++) {
        dis top = dis_queue.top();
        int top0 = std::get<0>(top);
        int top1 = std::get<1>(top);
        int top2 = std::get<2>(top);
        // std::cout << top0 << "," << top1 << "," << top2 << "," << top2 - top1 +1 << "\n";
        ans += (LL)(top2 - top1 +1);
        dis_queue.pop();
    }
 
    return ans;
}
 
int main() {
    int n, k;
    scanf("%d %d\n", &n, &k);
    int i = 0;
    int road[MAX_N][2];
    for (i = 0; i < n - 1; i ++) {
        scanf("%d %d", &road[i][0], &road[i][1]);
        if (road[i][0] > road[i][1]) {
            int t = road[i][0];
            road[i][0] = road[i][1];
            road[i][1] = t;
        }
    }
    printf("%lld\n", solve(n, k, road));
 
    return 0;
}

}
