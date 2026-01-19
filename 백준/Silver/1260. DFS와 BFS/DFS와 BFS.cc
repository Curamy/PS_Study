#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

int n, m, v;
int graph[1001][1001];
bool visited[1001];
queue<int> q;

void dfs(int x){
    visited[x] = true;
    cout << x << " ";

    for (int i = 1; i <= n; i++){
        if (graph[x][i] == 1 && !visited[i]){
            dfs(i);
        }
    }
}

void bfs(int x){
    visited[x] = true;
    q.push(x);

    while(!q.empty()){
        int v = q.front();
        q.pop();
        cout << v << " ";

        for (int i = 1; i <= n; i++){
            if (graph[v][i] == 1 && !visited[i]){
                q.push(i);
                visited[i] = true;
            }
        }
    }
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n >> m >> v;
    for (int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        graph[a][b] = 1;
        graph[b][a] = 1;
    }

    dfs(v);
    memset(visited, 0, sizeof(visited));
    cout << "\n";
    bfs(v);

    return 0;
}