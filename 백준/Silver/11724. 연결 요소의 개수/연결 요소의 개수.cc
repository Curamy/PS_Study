#include <iostream>
using namespace std;

int n, m;
int ans;
int graph[1001][1001];
bool visited[1001];

void dfs(int x){
    for(int i = 1; i <= n; i++){
        if (graph[x][i] == 1 && !visited[i]){
            visited[i] = true;
            dfs(i);
        }
    }
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n >> m;
    for (int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        graph[a][b] = 1;
        graph[b][a] = 1;
    }

    for (int i = 1; i <= n; i++){
        if (!visited[i]){
            ans++;
            dfs(i);
        }
    }

    cout << ans;

    return 0;
}