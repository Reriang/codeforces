#include <iostream>
#include <vector>
using namespace std;

void solve() {
    size_t n = 0; cin >> n;
    vector<long long> trees(n);
    long long hest = 0, ans = 1e18;
    for (auto &e : trees) {
        cin >> e;
        if (hest < e) hest = e;
    }
    for (long long h : {hest, hest + 1}) {
        long long l = 0, r = 1e18, tans = 1e18;
        while (l <= r) {
            long long mid = (l + r) >> 1;
            long long cnt1 = (mid + 1) / 2, cnt2 = mid - cnt1;
            long long need1 = 0;
            for (auto e : trees) {
                if ((h - e) % 2 == 1) need1 += 1;
                long long cur = (h - e) / 2;
                if (cnt2 >= cur) {
                    cnt2 -= cur;
                } else {
                    cur -= cnt2;
                    cnt2 = 0;
                    need1 += cur * 2;
                }
            }
            if (need1 <= cnt1) {
                tans = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        ans = min(ans, tans);
    }
    cout << ans << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 0; cin >> t;
    while (t--) solve();

    return 0;
}
