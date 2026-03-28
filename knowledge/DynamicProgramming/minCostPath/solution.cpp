#include <bits/stdc++.h>
using namespace std;

int findMinCost(size_t m, size_t n, vector<vector<int>> &cost, size_t x, size_t y) {
    if (x >= m || y >= n) return INT_MAX;

    if (x == m - 1 && y == n - 1) return cost[x][y];

    int right = findMinCost(m, n, cost, x, y + 1);
    int down = findMinCost(m, n, cost, x + 1, y);
    int diag = findMinCost(m, n, cost, x + 1, y + 1);

    int best = min(right, min(down, diag));

    return cost[x][y] + best;
}

void solve() {
    size_t m, n; cin >> m >> n;

    vector<vector<int>> cost(m, vector<int>(n, INT_MAX));
    for (auto &row : cost) 
        for (auto &e : row) 
            cin >> e;
    cout << findMinCost(m, n, cost, 0, 0);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1; cin >> t;
    while (t--) solve();

    return 0;
}
