#include <iostream>
#include <numeric>
#include <string>
#include <vector>
using namespace std;

void solve() {
    size_t n; cin >> n;
    vector<long long> arr(n);
    for (auto& e : arr) cin >> e;
    
    long long left = 0, right = 0;

    for (auto e : arr) {
        left += e;
        if (left <= 0) {
            cout << "NO\n";
            return ;
        }
    }
    for (auto it = arr.rbegin(); it != arr.rend(); ++it) {
        right += *it;
        if (right <= 0) {
            cout << "NO\n";
            return ;
        }
    }
    cout << "YES\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1; cin >> t;
    while (t--) solve();

    return 0;
}
