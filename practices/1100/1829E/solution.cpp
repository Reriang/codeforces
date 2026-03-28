#include <iostream>
#include <queue>
#include <vector>

using namespace std;

const int dx[4] = {1, -1, 0, 0};
const int dy[4] = {0, 0, 1, -1};

bool isValid(int x, int y, int n, int m) {
    return x >= 0 && x < n && y >= 0 && y < m;
}

int bfs(int x, int y, const vector<vector<int>> &lake, vector<vector<bool>> &visited, int n, int m) {
    int volume = 0;
    queue<pair<int, int>> q;
    q.push({x, y});
    visited[x][y] = true;
    while (!q.empty()) {
        auto [cx, cy] = q.front(); q.pop();
        volume += lake[cx][cy];
        for (int i = 0; i < 4; ++i) {
            int nx = cx + dx[i], ny = cy + dy[i];
            if (isValid(nx, ny, n, m) && !visited[nx][ny] && lake[nx][ny] != 0) {
                visited[nx][ny] = true;
                q.push({nx, ny});
            }
        }
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
                    max_volume = max(max_volume, bfs(i, j, lake, visited, n, m));
                
        cout << max_volume << "\n";
    }
    return 0;
}
