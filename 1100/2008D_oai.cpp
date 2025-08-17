#include <bits/stdc++.h>
using namespace std;

void solution(size_t n, vector<size_t> &permutation, string &black) {
    vector<bool> visited(n, false);
    vector<int> reach(n);
    for (auto num : permutation) {
        if (visited[num - 1]) continue;
        vector<size_t> cycle;
        int answer = 0;
        while (!visited[num - 1]) {
            visited[num - 1] = true;
            cycle.push_back(num - 1);
            if (black.at(num - 1) == '0') answer += 1;
            num = permutation[num - 1];
        }

        for (auto idx : cycle) reach[idx] = answer;
    }
    for (auto num : permutation) cout << reach[num - 1] << ' ';
    cout << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        size_t n;
        cin >> n;

        vector<size_t> permutation(n);
        string black;
        for (auto &e : permutation) cin >> e;
        cin >> black;
        solution(n, permutation, black);
    }
    return 0;
}