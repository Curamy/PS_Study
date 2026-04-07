#include <iostream>
using namespace std;

int n, m;
int ans;
int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, -1, 1};
int board[501][501];
int used[5][2];

void dfs(int y, int x, int u){
    if (u == 4){
        int sum = 0;
        for (int i = 1; i <= 4; i++){
            sum += board[used[i][0]][used[i][1]];
        }
        if (sum > ans){
            ans = sum;
        }
        return;
    }

    for (int i = 0; i < 4; i++){
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (ny > n || ny < 1 || nx > m || nx < 1){
            continue;
        }
        if (ny == used[u - 1][0] && nx == used[u - 1][1]){
            continue;
        }
        used[u + 1][0] = ny;
        used[u + 1][1] = nx;
        dfs(ny, nx, u + 1);

        if (u == 3){
            ny = used[2][0] + dy[i];
            nx = used[2][1] + dx[i];
            if (ny > n || ny < 1 || nx > m || nx < 1){
                continue;
            }
            if (ny == used[1][0] && nx == used[1][1]){
                continue;
            }
            if (ny == used[3][0] && nx == used[3][1]){
                continue;
            }
            used[u + 1][0] = ny;
            used[u + 1][1] = nx;
            dfs(ny, nx, u + 1);
        }
    }
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    
    ans = 0;
    cin >> n >> m;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            cin >> board[i][j];
        }
    }

    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            used[1][0] = i;
            used[1][1] = j;
            dfs(i, j, 1);
        }
    }

    cout << ans;

    return 0;
}