/*
 * ProblemID: Codeforces 1255B. Fridge Lockers
 */
#include <iostream>
#include <vector>
using namespace std;

void solve() {
    size_t n, m; cin >> n >> m;
    vector<int> fridges(n);
    for (auto &e : fridges) cin >> e;

    if (m < n || n < 3) cout << -1 << '\n';
    else {
        int ans = 0; 
        for (auto e : fridges) ans += e;
        cout << 2 * ans << '\n';
        for (size_t i = 1; i < m; ++i) {
            cout << i << ' ' << i + 1 << '\n';
        }
        cout << 1 << ' ' << m << '\n';
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1; cin >> t;

    while (t--) solve();

    return 0;
}
