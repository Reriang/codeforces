#include <bits/stdc++.h>
using namespace std;

void solution(size_t n, int k) {
    if (k % 2 == 0) {
        for (size_t i = 0; i < n - 2; ++i) cout << n - 1 << ' ';
        cout << n << ' ' << n - 1;
    } else {
        for (size_t i = 0; i < n - 1; ++i) cout << n << ' ';
        cout << n - 1;
    }
    cout << '\n';
}

int main()
{
    int t;
    cin >> t;
    while (t--) {
        size_t n;
        int k;
        cin >> n >> k;

        solution(n, k);
    }
    return 0;
}