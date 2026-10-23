#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
vector<vector<int>> grid;
vector<pair<int, int>> points;
bool visited[4][4];
int answer;

int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, -1, 1};

void backtracking(int row, int col, int level){
    if (row == points[level].first && col == points[level].second){
        level++;
    }

    if (level == m){
        answer++;
        return;
    }

    for (int d = 0; d < 4; d++){
        int ny = row + dy[d];
        int nx = col + dx[d];

        if (ny < 0 || ny == n || nx < 0 || nx == n){
            continue;
        }
        if (grid[ny][nx] == 1 || visited[ny][nx] == true){
            continue;
        }

        visited[ny][nx] = true;
        backtracking(ny, nx, level);
        visited[ny][nx] = false;
    }

}

int main() {
    cin >> n >> m;
    answer = 0;
    fill(visited[0], visited[5], false);

    grid.resize(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }

    points.resize(m);
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        points[i] = {x - 1, y - 1};
    }

    visited[points[0].first][points[0].second] = true;
    backtracking(points[0].first, points[0].second, 0);

    cout << answer;

    return 0;
}
