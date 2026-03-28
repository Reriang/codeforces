/*
 * Problem: Codeforces: A. DEMB and the Array 
 * Link: https://codeforces.com/
 * Author: Helieox
 * Date: 2026.03.24
 * 
 * Idea: 
 * - 
 * Complexity: 
 * - Time: 
 * - Space: 
*/
#include <iostream>
#include <vector>
using namespace std;

void solve() {
    size_t n; cin >> n;
    int s, x; cin >> s >> x;
    vector<int> arr(n);
    for (auto &e : arr) cin >> e;

    for (auto &e : arr) s -= e;
    if (s % x == 0 && s >= 0) cout << "YES\n";
    else cout << "NO\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1; cin >> t;
    while (t--) solve();

    return 0;
}
