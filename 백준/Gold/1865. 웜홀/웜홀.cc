#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define INF 9999999
using namespace std;

int n, m, w;
int dist[501][501];
vector<pair<int, int>> worms[501];

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    
    int t;
    cin >> t;

    for (int tc = 0; tc < t; tc++){
        cin >> n >> m >> w;

        for (int i = 1; i <= n; i++){
            worms[i].clear();
        }

        fill(dist[0], dist[501], INF);

        for (int i = 1; i <= n; i++){
            dist[i][i] = 0;
        }

        for (int i = 0; i < m; i++){
            int s, e, d;
            cin >> s >> e >> d;

            if (dist[s][e] > d){
                dist[s][e] = d;
            }
            if (dist[e][s] > d){
                dist[e][s] = d;
            }
        }

        for (int i = 0; i < w; i++){
            int s, e, d;
            cin >> s >> e >> d;
            worms[s].push_back({d, e});

            if (dist[s][e] > d * -1){
                dist[s][e] = d * -1;
            }
        }

        // 플로이드-워샬 알고리즘

        for (int k = 1; k <= n; k++){
            for (int i = 1; i <= n; i++){
                for (int j = 1; j <= n; j++){
                    if (dist[i][j] > dist[i][k] + dist[k][j]){
                        dist[i][j] = dist[i][k] + dist[k][j];
                    }
                }
            }
        }

        bool can = false;

        for (int i = 1; i <= n; i++){
            if (can){
                break;
            }

            for (auto wh : worms[i]){
                if (dist[wh.second][i] < wh.first){
                    can = true;
                    break;
                }
            }
        }

        if (can){
            cout << "YES\n";
        }
        else {
            cout << "NO\n";
        }
    }
    
    return 0;
}