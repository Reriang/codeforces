#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

void solve() {
    size_t n; cin >> n;
    vector<size_t> b(n), a(n, 0);
    for (auto &e : b) cin >> e;
    unordered_map<size_t, vector<size_t>> groups;
    for (size_t i = 0; i < n; ++i) groups[b[i]].push_back(i);

    size_t currentValue = 1;
    bool possible = true;

    for (auto &[freq, indices] : groups) {
        if (indices.size() % freq != 0) {
            possible = false;
            break;
        }
        for (size_t i = 0; i < indices.size(); i += freq) {
            for (size_t j = 0; j < freq; ++j)
                a[indices[i + j]] = currentValue;
            currentValue++;
        }
    }
    if (possible) {
        for (size_t i = 0; i < n; ++i)
            cout << a[i] << (i + 1 == n ? '\n' : ' ');
    } else 
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

