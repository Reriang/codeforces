#include <iostream>
#include <numeric>
#include <vector>
using namespace std;

class TwoColorsGraph
{
private:
    size_t V_;
    size_t E_;
    vector<vector<size_t>> adj;
    vector<bool> marked;
    vector<bool> color;
    size_t colored;

    void dfs(size_t v) {
        marked[v] = true;
        for (size_t w : adj[v]) {
            if (!marked[w]) {
                color[w] = !color[v];
                dfs(w);
            }
        }
    }

public:
    TwoColorsGraph(size_t V)
        : V_(V), E_(0), adj(V, vector<size_t>()), marked(V, false), color(V, false), colored(0)
    {
        for (auto &neighbors : adj) 
            neighbors.reserve(2);
    }

    void addEdge(size_t v, size_t w) {
        adj[v].push_back(w);
        adj[w].push_back(v);
        E_++;
    }

    size_t twoColor() {
        for (size_t s = 0; s < V_; ++s)
            if (!marked[s])
                dfs(s);
        colored = accumulate(color.begin(), color.end(), size_t(0));
        return colored;
    }
};


int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    size_t n, v, w;
    cin >> n;
    TwoColorsGraph G(n);
    for (size_t i = 1; i < n; ++i) {
        cin >> v >> w;
        --v, --w;
        G.addEdge(v, w);
    }
    size_t colored = G.twoColor();
    size_t maximum = colored * (n - colored);
    cout << maximum - n + 1 << '\n';
    return 0;
}