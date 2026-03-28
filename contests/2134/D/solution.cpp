/*
 * Problem: 
 * Link: https://codeforces.com/problemset/problem/2134/D
 * Author: Helieox
 * Date: 2026.03.19
 * 
 * Idea: 
 * - 
 * Complexity: 
 * - Time: O(n^2)
 * - Space: O(n)
*/
#include <iostream>
#include <limits>
#include <vector>
using namespace std;

void solve() {
    size_t n; cin >> n;
    vector<vector<size_t>> graph(n, vector<size_t>(n, 0));
    for (size_t i = 1; i < n; ++i) {
        size_t a, b; cin >> a >> b;
        graph[a-1][b-1] = 1;
        graph[b-1][a-1] = 1;
    }

    vector<size_t> dist(n), p(n);
    function<void(size_t, size_t)> dfs = [&](size_t now, size_t parent) {
        p[now] = parent;
        for (size_t i : graph[now]) {
            if (i != parent) {
                dist[i] = dist[now] + 1;
                dfs(i, now);
            }
        }
    };

    dist[0] = 0;
    dfs(0, -1);
    size_t x = max_element(dist.begin(), dist.end()) - dist.begin();
    dist[x] = 0;
    dfs(x, -1);
    size_t y = max_element(dist.begin(), dist.end()) - dist.begin();

    if (dist[y] == n - 1) {
        cout << -1 << '\n';
    } else {
        vector<int> on_diameter(n);
        size_t now = y;
        while (now != -1) {
            on_diameter[now] = 1;
            now = p[now];
        }

    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1; cin >> t;
    while (t--) solve();

    return 0;
}
