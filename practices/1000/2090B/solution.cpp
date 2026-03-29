/* Codeforeces: 2090B. Pushing Balls */
#include <iostream>
#include <vector>
#include <string>
using namespace std;

void solve() {
    size_t n, m; cin >> n >> m;
    vector<vector<int>> grid(n, vector<int>(m));
    vector<vector<bool>> valid(n, vector<bool>(m, false));
    bool possible = true;

    // Input
    for (size_t i = 0; i < n; ++i) {
        string s; cin >> s;
        for (size_t j = 0; j < m; ++j)
            grid[i][j] = s[j] - '0';
    }

    // Mark valid cells from rows (left to right)
    for (size_t i = 0; i < n; ++i) {
        for (size_t j = 0; j < m; ++j) {
            if (grid[i][j] == 0) break;
            valid[i][j] = true;
        }
    }
    
    // Mark valid cells from columns (top to bottom)
    for (size_t j = 0; j < m; ++j) {
        for (size_t i = 0; i < n; ++i) {
            if (grid[i][j] == 0) break;
            valid[i][j] = true;
        }
    }
    // Check if all '1's are valid
    for (size_t i = 0; i < n && possible; ++i) {
        for (size_t j = 0; j < m; ++j) {
            if (grid[i][j] == 1 && !valid[i][j])
                possible = false;
        }
    }

    cout << (possible ? "YES\n" : "NO\n");
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    size_t t = 1; cin >> t;
    while (t--) solve();

    return 0;
}
