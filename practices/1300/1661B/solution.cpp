#include <iostream>
using namespace std;

void solve() {
    int num = 0; cin >> num;
    int cnt = 15;
    int answer = 15;
    for (int i = 0; i < cnt; ++i) {
        int result = num + i;
        for (int j = 0; j <= (cnt - i); ++j) {
            if (result % 32768 == 0 && (i + j) < answer)
                answer = i + j;
            result *= 2;
        }
    }
    cout << answer << ' ';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1; cin >> t;
    while (t--) solve();
    cout << '\n';
    
    return 0;
}
