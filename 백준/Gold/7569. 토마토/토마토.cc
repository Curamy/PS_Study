#include <iostream>
#include <queue>
#include <tuple>
using namespace std;

int n, m, h;
int storage[101][101][101];
int day[101][101][101];
queue<tuple<int, int, int>> q;

int gorip(int z, int x, int y){
    if (z == 1 || storage[z - 1][x][y] == -1){ // 위쪽이 막힌 경우
        if (z == h || storage[z + 1][x][y] == -1){ // 아래가 막힌 경우
            if (x == 1 || storage[z][x - 1][y] == -1){ // 왼쪽이 막힌 경우
                if (x == n || storage[z][x + 1][y] == -1){ // 오른쪽이 막힌 경우
                    if (y == 1 || storage[z][x][y - 1] == -1){  //앞이 막힌 경우
                        if (y == m || storage[z][x][y + 1] == -1){  // 뒤가 막힌 경우
                            return -1;
                        }
                    }
                }
            }
        }
    }

    return 1;
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> m >> n >> h;
    for (int i = 1; i <= h; i++){
        for (int j = 1; j <= n; j++){
            for (int k = 1; k <= m; k++){
                cin >> storage[i][j][k];
            }
        }
    }

    bool already = true;    // 이미 다 익어 있는 경우 체크

    for (int i = 1; i <= h; i++){
        for (int j = 1; j <= n; j++){
            for (int k = 1; k <= m; k++){
                if (storage[i][j][k] == 0){
                    already = false;    // 하나라도 0이 있다면 아님
                    if (gorip(i, j, k) == -1){ // 고립된 토마토가 있는 경우 -1
                        cout << -1;
                        return 0;
                    }
                }
            }
        }
    }

    if (already == true){   // 이미 다 익어 있는 상태면 0
        cout << 0;
        return 0;
    }

    for (int i = 1; i <= h; i++){
        for (int j = 1; j <= n; j++){
            for (int k = 1; k <= m; k++){
                if (storage[i][j][k] == 1){
                    q.push({i, j, k});
                }
            }
        }
    }

    while(!q.empty()){  // tuple(3개) 인자 접근
        int z = get<0>(q.front());
        int x = get<1>(q.front());
        int y = get<2>(q.front());
        q.pop();

        if (z != 1 && storage[z - 1][x][y] == 0){   // 위
            storage[z - 1][x][y] = 1;
            q.push({z - 1, x, y});
            day[z - 1][x][y] = day[z][x][y] + 1;
        }

        if (z != h && storage[z + 1][x][y] == 0){   // 아래
            storage[z + 1][x][y] = 1;
            q.push({z + 1, x, y});
            day[z + 1][x][y] = day[z][x][y] + 1;
        }

        if (x != 1 && storage[z][x - 1][y] == 0){  // 왼쪽
            storage[z][x - 1][y] = 1;
            q.push({z, x - 1, y});
            day[z][x - 1][y] = day[z][x][y] + 1;
        }

        if (x != n && storage[z][x + 1][y] == 0){  // 오른쪽
            storage[z][x + 1][y] = 1;
            q.push({z, x + 1, y});
            day[z][x + 1][y] = day[z][x][y] + 1;
        }

        if (y != 1 && storage[z][x][y - 1] == 0){  // 앞
            storage[z][x][y - 1] = 1;
            q.push({z, x, y - 1});
            day[z][x][y - 1] = day[z][x][y] + 1;
        }

        if (y != m && storage[z][x][y + 1] == 0){  // 뒤
            storage[z][x][y + 1] = 1;
            q.push({z, x, y + 1});
            day[z][x][y + 1] = day[z][x][y] + 1;
        }
    }

    int ans = 0;
    for (int i = 1; i <= h; i++){
        for (int j = 1; j <= n; j++){
            for (int k = 1; k <= m; k++){
                if (storage[i][j][k] == 0){    // 다 익지 못하는 경우
                    cout << -1;
                    return 0;
                }
                if (day[i][j][k] > ans){
                    ans = day[i][j][k];
                }
            }
        }
    }

    cout << ans;

    return 0;
}