#include <iostream>
#include <algorithm>
#include <vector>
#define INF 99999999
using namespace std;

int n, m;
int dist[101][101];
int nxt[101][101];

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n >> m;
    fill(dist[0], dist[101], INF);
    fill(nxt[0], nxt[101], 0);

    for (int i = 0; i < m; i++){
        int s, e, w;
        cin >> s >> e >> w;
        
        if (dist[s][e] > w){
            dist[s][e] = w;
            nxt[s][e] = e;
        }
    }

    for (int i = 1; i <= n; i++){
        dist[i][i] = 0;
    }

    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            for (int k = 1; k <= n; k++){
                if (dist[j][k] > dist[j][i] + dist[i][k]){
                    dist[j][k] = dist[j][i] + dist[i][k];
                    nxt[j][k] = nxt[j][i];
                }
            }
        }
    }

    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            if (dist[i][j] == INF){
                cout << "0 ";
            }
            else{
                cout << dist[i][j] << " ";
            }
        }
        cout << "\n";
    }

    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            if (dist[i][j] == INF || dist[i][j] == 0){
                cout << "0 \n";
            }
            else{
                vector<int> path;
                int cur = i;
                while (cur != j){
                    path.push_back(cur);
                    cur = nxt[cur][j];
                }
                path.push_back(j);
                cout << path.size() << " ";
                for (int i = 0; i < path.size(); i++){
                    cout << path[i] << " ";
                }
                cout << "\n";
            }
        }
    }

    return 0;
}