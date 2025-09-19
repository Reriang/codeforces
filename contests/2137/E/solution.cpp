#includ <iostream>
#include <vector>
using namespace std;
using ll = long long;

void solve() {
    size_t n; cin >> n;
    ll k; cin >> k;
	vector<size_t> a(n);
	for (auto &e : a) cin >> e;

	ll limit = min(k, (k % 2) + 2);

	for (ll it = 0; it < limit; ++it) {
		vector<size_t> freq(n+1, 0);
		for (auto e : a) ++freq[e];
		size_t mex = 0; 
		while (mex <= n && freq[mex] > 0) ++mex;
		vector<size_t> b(n);
		for (size_t i = 0; i < n; ++i) {
			size_t val = a[i];
			if (val < mex) {
				if (freq[val] == 1) b[i] = val;
				else b[i] = mex;
			} else {
				b[i] = mex;
			}
		}
		if (b == a) break;
		a.swap(b);
	}
	ll sum = 0; 
	for (auto e : a) sum += e;
	cout << sum << '\n';
}

int
main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1; cin >> t;
    while (t--) solve();
    return 0;
}
