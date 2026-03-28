#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

/*
Codeforces: 1829F. Forever Winter
Link: https://codeforces.com/problemset/problem/1829/F
Tags: dfs, graphs math
*/

class Graph
{
private:
    size_t V_;
    size_t E_;
    vector<vector<size_t>> adj;

public:
    Graph(size_t V)
        : V_(V), E_(0), adj(V, vector<size_t>()) {}

    void addEdge(size_t v, size_t w) {
        adj[v].push_back(w);
        adj[w].push_back(v);
        E_++;
    }

    const vector<size_t>& adjacents(size_t v) const {
        return adj[v];
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        size_t n, m;
        cin >> n >> m;

        Graph G(n);
        while (m--) {
            size_t v, w;
            cin >> v >> w;
            G.addEdge(v-1, w-1);
        }

        unordered_map<size_t, size_t> degreeCount;
        for (size_t i = 0; i < n; ++i) {
            degreeCount[G.adjacents(i).size()]++;
        }
        size_t x = 0, y = 0;
        for (auto [deg, count] : degreeCount) {
            if (deg == 1) continue;
            if (count == 1)
                x = deg;
            else 
                y = deg - 1;
        }
        if (x == 0) x = y + 1;
        cout << x << ' ' << y << '\n';
    }
    return 0;
}
