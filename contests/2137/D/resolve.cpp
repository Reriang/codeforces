#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

void solve() {
    size_t n; cin >> n;
    vector<size_t> a(n, 0), b(n);
    for (auto &e : b) cin >> e;
    unordered_map<size_t, vector<size_t>> groups;
    for (size_t i = 0; i < n; ++i) {
        groups[b[i]].push_back(i);
    }
    bool possible = true;
    size_t value = 0;
    for (auto &[freq, indices] : groups) {
        if (indices.size() % freq != 0) {
            possible = false;
            break;
        }
        for (size_t i = 0; i < indices.size(); i += freq) {
            value++;
            for (size_t j = 0; j < freq; ++j)
                a[indices[i + j]] = value;
        }
    }
    if (possible) 
        for (size_t i = 0; i < n; ++i) cout << a[i] << (i == n - 1  ? '\n' : ' ');
    else 
        cout << -1 << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1; cin >> t;
    while (t--) solve();
    return 0;
}
