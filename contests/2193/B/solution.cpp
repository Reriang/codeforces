/*
 * Problem: Codeforces: B. Reverse a Permutation
 * Link: https://codeforces.com/
 * Author: Helieox
 * Date: 
 * 
 * Idea: 
 * - 
 * Complexity: 
 * - Time: 
 * - Space: 
*/
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

void solve() {
    size_t n; cin >> n;
    vector<size_t> arr(n);
    for (auto &e : arr) cin >> e;

    size_t left = n, right = n;
    for (size_t i = 0; i < n; ++i) {
        if (arr[i] == n - i) continue;
        else if (left == n && arr[i] != n - i) left = i;
        if (arr[i] == n - left) right = i;
    }
    if (left != right) {
        for (size_t i = 0; i < left; ++i) cout << arr[i] << ' ';
        for (size_t i = right + 1; i-- > left; ) cout << arr[i] << ' ';
        for (size_t i = right + 1; i < n; ++i) cout << arr[i] << ' ';
    }
    if (left == right)
        for (size_t &e : arr) cout << e << ' ';
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1; cin >> t;
    while (t--) solve();

    return 0;
}
