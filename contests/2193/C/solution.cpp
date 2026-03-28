/*
 * Problem: Codeforces: C. Replace and Sum
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
    size_t n, q; cin >> n >> q;
    vector<long> arr(n), brr(n);
    for (auto &e : arr) cin >> e;
    for (auto &e : brr) cin >> e;

    for (auto &e : arr) cout << e << ' ';
    cout << '\n';
    for (auto &e : brr) cout << e << ' ';
    cout << '\n';

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1; cin >> t;
    while (t--) solve();

    return 0;
}
