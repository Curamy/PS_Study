#include <bits/stdc++.h>
#include <algorithm>

using namespace std;

int N, T;
vector<vector<int>> grid;

int dp[1000][1000][2];

int dy[2] = {0, 1};
int dx[2] = {1, 0};

int backtracking(int y, int x, int remain) {
    if (remain == 0) {
        return grid[y][x];
    }

    int result = -9999999;

    for (int dir = 0; dir < 2; dir++) {
        int ny = y + dy[dir];
        int nx = x + dx[dir];

        if (ny >= N || nx >= N) {
            continue;
        }

        int next = backtracking(ny, nx, remain - 1);

        if (next != -9999999) {
            result = max(result, grid[y][x] + next);
        }
    }

    return result;
}

int main() {
    cin.tie(nullptr);

    cin >> N >> T;

    grid.resize(N, vector<int>(N));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> grid[i][j];
        }
    }

    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            dp[i][j][0] = -9999999;
            dp[i][j][1] = -9999999;
        }
    }

    dp[0][0][0] = grid[0][0];

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {

            if (i > 0) {
                dp[i][j][0] = max(dp[i][j][0], dp[i - 1][j][0] + grid[i][j]);
                dp[i][j][1] = max(dp[i][j][1], dp[i - 1][j][1] + grid[i][j]);
            }

            if (j > 0) {
                dp[i][j][0] = max(dp[i][j][0], dp[i][j - 1][0] + grid[i][j]);
                dp[i][j][1] = max(dp[i][j][1], dp[i][j - 1][1] + grid[i][j]);
            }

            int gain = backtracking(i, j, T);

            if (gain != -9999999) {
                dp[i][j][1] = max(dp[i][j][1], dp[i][j][0] + gain);
            }
        }
    }

    cout << max(dp[N - 1][N - 1][0], dp[N - 1][N - 1][1]);

    return 0;
}