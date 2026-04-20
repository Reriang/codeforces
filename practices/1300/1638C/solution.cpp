#include <iostream>
#include <vector>
#include <stack>
#include <numeric>
#include <utility>
using namespace std;

// 1638C. Inversion Graph, https://codeforces.com/problemset/problem/1638/C

void solve() {
    size_t n; cin >> n;
    vector<size_t> p(n);
    for (auto &e : p) cin >> e;

    // stack of {min, max}
    vector<pair<size_t, size_t>> st;

    for (size_t i = 0; i < n; ++i) {
        st.push_back({p[i], p[i]});

        while (st.size() >= 2) {
            auto top = st.back(); st.pop_back();
            auto below = st.back(); st.pop_back();

            size_t min1 = top.first, max1 = top.second;
            size_t min2 = below.first, max2 = below.second;
            if (max2 > min1) {
                size_t newMin = min1 < min2 ? min1 : min2;
                size_t newMax = max1 > max2 ? max1 : max2;
                st.push_back({newMin, newMax});
            } else {
                st.push_back(below);
                st.push_back(top);
                break;
            }
        }
    }
    cout << st.size() << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1; cin >> t;
    while (t--) solve();

    return 0;
}
