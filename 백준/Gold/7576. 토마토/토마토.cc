#include <iostream>
#include <queue>
using namespace std;

int n, m;
int storage[1001][1001];
int day[1001][1001];
queue<pair<int, int>> q;

int gorip(int x, int y){
    if (x == 1 || storage[x - 1][y] == -1){ // 위쪽이 막힌 경우
        if (x == n || storage[x + 1][y] == -1){ // 아래가 막힌 경우
            if (y == 1 || storage[x][y - 1] == -1){ // 왼쪽이 막힌 경우
                if (y == m || storage[x][y + 1] == -1){ // 오른쪽이 막힌 경우
                    return -1;
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

    cin >> m >> n;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            cin >> storage[i][j];
        }
    }

    bool already = true;    // 이미 다 익어 있는 경우 체크

    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            if (storage[i][j] == 0){
                already = false;    // 하나라도 0이 있다면 아님
                if (gorip(i, j) == -1){ // 고립된 토마토가 있는 경우 -1
                    cout << -1;
                    return 0;
                }
            }
        }
    }

    if (already == true){   // 이미 다 익어 있는 상태면 0
        cout << 0;
        return 0;
    }

    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            if (storage[i][j] == 1){
                q.push({i, j});
            }
        }
    }

    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        if (x != 1 && storage[x - 1][y] == 0){  // 위
            storage[x - 1][y] = 1;
            q.push({x - 1, y});
            day[x - 1][y] = day[x][y] + 1;
        }

        if (x != n && storage[x + 1][y] == 0){  // 아래
            storage[x + 1][y] = 1;
            q.push({x + 1, y});
            day[x + 1][y] = day[x][y] + 1;
        }

        if (y != 1 && storage[x][y - 1] == 0){  // 왼쪽
            storage[x][y - 1] = 1;
            q.push({x, y - 1});
            day[x][y - 1] = day[x][y] + 1;
        }

        if (y != m && storage[x][y + 1] == 0){  // 오른쪽
            storage[x][y + 1] = 1;
            q.push({x, y + 1});
            day[x][y + 1] = day[x][y] + 1;
        }
    }

    int ans = 0;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            if (storage[i][j] == 0){    // 다 익지 못하는 경우
                cout << -1;
                return 0;
            }
            if (day[i][j] > ans){
                ans = day[i][j];
            }
        }
    }

    cout << ans;

    return 0;
}