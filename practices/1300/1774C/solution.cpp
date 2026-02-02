#include <iostream>
#include <string>
#include <vector>
using namespace std;

void solve() {
    size_t n; cin >> n;
    string envs; cin >> envs;
    size_t cons = 0;
    char prev = envs[0];
    for (size_t i = 0; i < n - 1; ++i) {
        if (envs[i] == prev) cons += 1;
        else cons = 1;
        prev = envs[i];
        cout << i - cons + 2 << ' ';
    }

    cout << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1; cin >> t;
    while (t--) solve();

    return 0;
}
