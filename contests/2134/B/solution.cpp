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
    size_t n, k;
    cin >> n >> k;
    vector<long long> arr(n);
    for (auto &e : arr) cin >> e;

    if (n == 1) arr[0] += k;

    if (k % 2 != 0) {
        for (auto &e : arr)
            if (e % 2 != 0) e += k;
    } else if ()

    for (auto &e : arr) cout << e << ' ';
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1; cin >> t;
    while (t--) solve();

    return 0;
}
