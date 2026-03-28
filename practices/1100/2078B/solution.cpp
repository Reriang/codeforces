#include <bits/stdc++.h>
using namespace std;

void solution(size_t n, int k) {
    if (k % 2 == 0) {
        vector<size_t> answer(n, n-1);
        answer[n-2] = n;
        for (auto e : answer) cout << e << ' ';
    } else {
        vector<size_t> answer(n, n);
        answer[n-1] = n - 1;
        for (auto e : answer) cout << e << ' ';
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
