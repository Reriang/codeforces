#include <iostream>
#include <vector>
using namespace std;

/*
tags: binary search, greedy
 */

void solve() {
    size_t n = 0; cin >> n;
    vector<long long> trees(n);
    long long hest = 0, ans = 1e18;
    for (auto &e : trees) {
        cin >> e;
        if (hest < e) hest = e;
    }
    for (long long h : {hest, hest + 1}) {
        long  long cnt1 = 0, cnt2 = 0;
        for (size_t i = 0; i < n; i++) {
            cnt1 += (h - trees[i]) % 2;
            cnt2 += (h - trees[i]) / 2;
        }
        long long diff = max(0ll, cnt2 - cnt1 - 1) / 3;
        cnt1 += diff * 2;
        cnt2 -= diff;
        ans = min(ans, max(cnt1 * 2 - 1, cnt2 * 2));
        if (cnt2 > 0) {
            cnt1 += 2;
            --cnt2;
            ans = min(ans, max(cnt1 * 2 - 1, cnt2 * 2));
        }
    }
    cout << ans << '\n';
}

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1; cin >> t;
    while (t--) solve();

    return 0;
}
