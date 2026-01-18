#include <iostream>
#include <queue>
using namespace std;

int n, m;
int board[1001][1001];
int dist[1001][1001];
bool visited[1001][1001];
queue<pair<int, int>> q;

void bfs(){
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        if (x - 1 >= 1 && !visited[x - 1][y] && board[x - 1][y] != 0){
            q.push(make_pair(x - 1, y));
            visited[x - 1][y] = true;
            dist[x - 1][y] = dist[x][y] + 1;
        }

        if (x + 1 < 1001 && !visited[x + 1][y] && board[x + 1][y] != 0){
            q.push(make_pair(x + 1, y));
            visited[x + 1][y] = true;
            dist[x + 1][y] = dist[x][y] + 1;
        }

        if (y - 1 >= 1 && !visited[x][y - 1] && board[x][y - 1] != 0){
            q.push(make_pair(x, y - 1));
            visited[x][y - 1] = true;
            dist[x][y - 1] = dist[x][y] + 1;
        }

        if (y + 1 < 1001 && !visited[x][y + 1] && board[x][y + 1] != 0){
            q.push(make_pair(x, y + 1));
            visited[x][y + 1] = true;
            dist[x][y + 1] = dist[x][y] + 1;
        }
    }
}

void print(){
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            if (board[i][j] == 1 && dist[i][j] == 0){
                cout << "-1 "; 
            }
            else{
                cout << dist[i][j] << " ";
            }
        }
        cout << "\n";
    }
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n >> m;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            cin >> board[i][j];
            if (board[i][j] == 2){
                q.push(make_pair(i, j));
                visited[i][j] = true;
            }
        }
    }

    bfs();
    print();

    return 0;
}