#include <iostream>
#include <vector>

using namespace std;

const int dx[4] = {1, -1, 0, 0};
const int dy[4] = {0, 0, 1, -1};

bool isValid(int x, int y, int n, int m) {
    return x >= 0 && x < n && y >= 0 && y < m;
}

int dfs(int x, int y, const vector<vector<int>> &lake, vector<vector<bool>> &visited, int n, int m) {
    if (!isValid(x, y, n, m) || visited[x][y] || lake[x][y] == 0)
        return 0;

    visited[x][y] = true;
    int volume = lake[x][y];

    for (int i = 0; i < 4; ++i) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        volume += dfs(nx, ny, lake, visited, n, m);
    }
    return volume;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    std::cin >> t;
    while (t--) {
        int n, m;
        std::cin >> n >> m;
        vector<vector<int>> lake(n, vector<int>(m));
        vector<vector<bool>> visited(n, vector<bool>(m, false));

        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
                cin >> lake[i][j];

        int max_volume = 0;
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j) 
                if (!visited[i][j] && lake[i][j] != 0) 
                    max_volume = max(max_volume, dfs(i, j, lake, visited, n, m));
                
        cout << max_volume << "\n";
    }
    return 0;
}