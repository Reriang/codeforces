/*
 * Problem: Codeforces Problem 2112B. Shrinking Array
 * Link: https://codeforces.com/problemset/problem/2112/B
 * Author: Helieox
 * Date: 2026-03-16
 *
 * Idea:
 * - Greedy
 * - Array Properties
 * Complexity:
 * - Time: O(n)
 * - Space: O(1)
*/

#include <iostream>
#include <vector>
using namespace std;


void solve() {
    size_t n; cin >> n;
    vector<int> a(n);
    for (auto &e : a) cin >> e;

    bool zero = false, none = false;
    if (n == 2 && abs(a[0] - a[1]) <= 1)
        zero = true;
    else if (n == 2)
        none = true;

    bool inc = false, dec = false;
    for (size_t i = 1; i < n; ++i) {
        if (zero) break;
        if (abs(a[i] - a[i-1]) <= 1)
            zero = true;
        else if (a[i] > a[i-1]) 
            inc = true;
        else if (a[i] < a[i-1])                
            dec = true;
    }
    if (zero)               cout << 0 << '\n';
    else if (inc && dec)    cout << 1 << '\n';
    else if (inc ^ dec)     cout << -1 << '\n';
    else if (none)          cout << -1 << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1; cin >> t;
    while (t--) solve();

    return 0;
}
