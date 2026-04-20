/*
 * Problem: 2134B. Add 0 or K
 * Link: https://codeforces.com/problemset/problem/2134/B
 * Author: Helieox
 * Date: 2026.03.17
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
    long long k; cin >> k;
    vector<long long> arr(n);
    for (auto &e : arr) cin >> e;

    for (auto &e : arr) {
        long long c = e % (k + 1);
        e += k * c;
    }

    for (auto e : arr) cout << e << ' ';
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1; cin >> t;
    while (t--) solve();

    return 0;
}
