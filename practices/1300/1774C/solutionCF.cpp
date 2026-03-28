#include <bits/stdc++.h>
using namespace std;


void solve() {
   size_t n; cin >> n;
   string s; cin >> s;
   size_t last0 = 0, last1 = 0;
   for (size_t i = 0; i < n - 1; ++i) {
       if (s[i] == '0') {
           cout << last1 + 1 << ' ';
           last0 = i + 1;
       } else {
           cout << last0 + 1 << ' ';
           last1 = i + 1;
       }
   }
   cout << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) solve();

    return 0;
}
