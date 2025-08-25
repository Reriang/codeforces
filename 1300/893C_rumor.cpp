#include <iostream>
#include <vector>
using namespace std;

struct UF
{
    vector<size_t> id;
    vector<size_t> sz;
    size_t countComponents;
    UF(size_t n)
        : id(), sz(n, 1), countComponents(n)
    {
        for (size_t i = 0; i < n; ++i) id.push_back(i);
    }

    size_t find(size_t x) {
        while (x != id[x]) x = id[x];
        return x;
    }

    void unionUF(size_t p, size_t q, vector<long long> &costs) {
        p = find(p); q = find(q);
        if (p == q) return ;
        if (sz[p] < sz[q]) {
            id[p] = q;
            sz[p] += sz[p];
            costs[q] = min(costs[p], costs[q]);
        } else {
            id[q] = p;
            sz[p] = sz[q];
            costs[p] = min(costs[p], costs[q]);
        }
        countComponents--;
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    size_t n, m;
    cin >> n >> m;

    vector<long long> costs(n);
    for (auto &c : costs) cin >> c;

    UF uf(n);
    for (size_t i = 0; i < m; ++i) {
        size_t p, q;
        cin >> p >> q;
        uf.unionUF(p-1, q-1, costs);
    }

    long long total = 0;
    for (size_t i = 0; i < n; ++i)
        if (i == uf.find(i)) total += costs[i];

    cout << total << '\n';
    return 0;
}