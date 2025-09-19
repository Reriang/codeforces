#include <iostream>
#include <numeric>
#include <vector>
using namespace std;

struct DSU {
    vector<int> parent, rank;
    vector<long long> minCost;
    DSU(int n, vector<long long> &costs) {
        parent.resize(n);
        rank.assign(n, 0);
        minCost = costs;
        iota(parent.begin(), parent.end(), 0);
    }
    size_t find(size_t x) {
        if (parent[x] != x) parent[x] = find(parent[x]);
        return parent[x];
    }
    void unite(size_t a, size_t b) {
        a = find(a); b = find(b);
        if (a == b) return ;
        if (rank[a] < rank[b]) swap(a, b);
        parent[b] = a;
        minCost[a] = min(minCost[a], minCost[b]);
        if (rank[a] == rank[b]) rank[a]++; 
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    size_t n;
    int m;
    cin >> n >> m;

    vector<long long> costs(n);
    for (auto &c : costs) cin >> c;

    DSU dsu(n ,costs);
    for (int i = 0; i < m; ++i) {
        size_t a, b;
        cin >> a >> b;
        dsu.unite(a-1, b-1);
    }

    long long total = 0;
    vector<bool> added(n, false);
    for (int i = 0; i < n; ++i) {
        int root = dsu.find(i);
        if (!added[root]) {
            total += dsu.minCost[root];
            added[root] = true;
        }
    }
    cout << total << '\n';
    return 0;
}