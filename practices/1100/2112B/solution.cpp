#include <iostream>
using namespace std;

void solve() {
    size_t n; cin >> n;
    vector<int> a(n);
    for (auto &e : a) cin >> e;

    for (size_t i = 1; i < n; ++i) {
        if (abs(a[i - 1] - a[i]) <= 1) {
            cout << 0 << endl;
            return ;
        }
    }
    for (size_t i = 1; i + 1 < n; ++i) {
        if 
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1; cin >> t;
    while (t--) solve();
    cout << "Hello, World!" << endl;
    return 0;
}
