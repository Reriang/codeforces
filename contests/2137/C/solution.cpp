#include <iostream>
#include <vector>
using namespace std;

void solve() {
    unsigned long long a, b; cin >> a >> b;
    unsigned long long answer = 0;
    if (b % 2 != 0) {
        if (a % 2 != 0) answer = a * b + 1;
        else answer = 0;
    } else {
        unsigned long long low = b & -b;
        if (a % 2 != 0 && low == 2) answer = 0;
        else answer = a * (b / 2) + 2;
    }
    if (answer == 0) cout << -1;
    else cout << answer;
    cout << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1; cin >> t;
    while (t--) solve();
    return 0;
}

