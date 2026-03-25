#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <queue>
using namespace std;

struct Move {       // 현재 y좌표, x좌표, 이동 거리, 관통 가능 여부
    int y;
    int x;
    int dist;
    bool pen;

    bool operator< (const Move &o) const {
        if (dist != o.dist){
            return dist > o.dist;
        }

        if (pen != o.pen) {
            return pen < o.pen;
        }

        if (y != o.y){
            return y < o.y;
        }

        return x < o.x;
    }
};

int n, m;
bool board[1001][1001];
bool visited[1001][1001][2];        // 1: 벽을 부수지 않은 경우의 방문, 0: 벽을 부순 경우
priority_queue<Move> pq;

int dy[] = {-1, 1, 0, 0};
int dx[] = {0, 0, -1, 1};

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n >> m;

    memset(visited, 0, sizeof(visited));

    for (int i = 1; i <= n; i++){
        string str;
        cin >> str;

        for (int j = 0; j < m; j++){
            board[i][j + 1] = str[j] - '0';
        }
    }

    pq.push({1, 1, 1, 1});
    visited[1][1][0] = true;
    visited[1][1][1] = true;
    
    while (!pq.empty()){
        int y = pq.top().y;
        int x = pq.top().x;
        int dist = pq.top().dist;
        bool pen = pq.top().pen;
        pq.pop();

        if (y == n && x == m){      // 목적지에 도착했다면
            cout << dist;
            return 0;
        }
        
        for (int i = 0; i < 4; i++){
            int ny = y + dy[i];
            int nx = x + dx[i];

            if (ny < 1 || ny > n || nx < 1 || nx > m){
                continue;
            }

            if (board[ny][nx] == 1 && pen == 0){
                continue;
            }

            if (board[ny][nx] == 1 && pen == 1){
                if (!visited[ny][nx][0]){
                    pq.push({ny, nx, dist + 1, 0});
                    visited[ny][nx][0] = true;
                }
            }

            if (board[ny][nx] == 0){
                if (!visited[ny][nx][pen]){
                    pq.push({ny, nx, dist + 1, pen});
                    visited[ny][nx][pen] = true;
                }
            }
        }
    }

    cout << -1;

    return 0;
}