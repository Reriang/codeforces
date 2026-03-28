/*
 * Problem: 2134 C. Even Larger
 * Link: https://codeforces.com/problemset/problem/2134/C
 * Author: Helieox
 * Date: 2026.03.18
 * 
 * Idea: 
 * - Implementation
 * Complexity: 
 * - Time: O(n)
 * - Space: O(1)
*/
#include <iostream>
#include <vector>
using namespace std;

void solve() {
    size_t n; cin >> n;
    vector<long long> arr(n);
    for (auto &e : arr) cin >> e;

    long long ans = 0;
    for (size_t i = 1; i < n; i+=2) {
        if (arr[i-1] > arr[i]) {
            long long dec = arr[i-1] - arr[i];
            arr[i-1] -= dec;
            ans += dec;
        } 
        if (i != n - 1 && (arr[i-1] + arr[i+1]) > arr[i]) {
            long long dec = arr[i-1] + arr[i+1] - arr[i];
            arr[i+1] -= dec;
            ans += dec;
        }
    }
    cout << ans << '\n';
}



int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1; cin >> t;
    while (t--) solve();

    return 0;
}
