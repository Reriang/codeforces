#include <iostream>
#include <vector>
using namespace std;


void solve() {
    size_t n; cin >> n;
    vector<size_t> a(n), b(n);
    for (auto &e : a) cin >> e;
    for (auto &e : b) cin >> e;

    vector<size_t> prefixMax(n);
    prefixMax[0] = a[0];
    for (size_t i = 1; i < n; ++i)
        prefixMax[i] = max(prefixMax[i - 1], a[i]);

    unsigned long long ans = 0;
    size_t l = 0;
    while (l < n) {
        size_t curMax = prefixMax[l];
        size_t r = l;
        while (r < n && prefixMax[r] == curMax) r++;

        for (size_t i = l; i < r; ++i) {
            if (b[i] <= curMax) {
                unsigned long long left = i - l + 1;
                unsigned long long right = r - i;
                ans += left * right;
            }
        }
        l = r;
    }
    cout << ans << "\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1; cin >> t;
    while (t--) solve();
    return 0;
}
