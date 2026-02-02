#include <iostream>
using namespace std;

void solve() {
    int num = 0; cin >> num;
    int ans = 15;
    for (int cntAdd = 0; cntAdd < 15; ++cntAdd)
        for (int cntMul = 0; cntMul < 15; ++cntMul)
            if (((num + cntAdd) << cntMul) % 32768 == 0)
                ans = (cntAdd + cntMul) < ans ? (cntAdd + cntMul) : ans;
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
