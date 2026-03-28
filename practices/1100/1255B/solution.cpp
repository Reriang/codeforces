#include <bits/stdc++.h>
using namespace std;

void solution(size_t n, size_t m, vector<int> &fridge) {
    if (n == 2 || m < n) {
        cout << -1 << '\n'; 
        return ;
    }
    int cost = accumulate(fridge.begin(), fridge.end(), 0);
    cout << cost * 2 << '\n';
    for (size_t i = 1; i < n; ++i) 
        cout << i << ' ' << i + 1 << '\n';
    cout << n << ' ' << 1 << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;

    while (t--) {
        size_t n, m;
        cin >> n >> m;

        vector<int> fridge(n);
        for (auto &e : fridge) cin >> e;
        solution(n, m, fridge);
    }
    return 0;
}
