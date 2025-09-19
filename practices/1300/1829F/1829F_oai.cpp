#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

/*
Codeforces: 1829F. Forever Winter
Link: https://codeforces.com/problemset/problem/1829/F
*/

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        size_t n, m;
        cin >> n >> m;

        vector<size_t> deg(n);
        while (m--) {
            size_t v, w;
            cin >> v >> w;
            deg[--v]++;
            deg[--w]++;
        }
        unordered_map<size_t, size_t> degreeCount;
        for (size_t i = 0; i < n; ++i)
            degreeCount[deg[i]]++;
        
        size_t x = 0, y = 0;
        for (auto [deg, cnt] : degreeCount) {
            if (deg == 1) continue;
            if (cnt == 1) x = deg;
            else y = deg - 1;
        }
        if (x == 0) x = y + 1;
        cout << x << ' ' << y << '\n';
    }
    return 0;
}