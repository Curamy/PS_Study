#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
#include <algorithm>
#define INF 500000
using namespace std;

int v, e, k;
vector<pair<int, int>> dist[20001];
int dijkstra[20001];

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> v >> e;
    cin >> k;

    fill(dijkstra, dijkstra + 20001, INF);

    for (int i = 0; i < e; i++){
        int v1, v2, w;
        cin >> v1 >> v2 >> w;
        dist[v1].push_back({w, v2});
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    dijkstra[k] = 0;
    pq.push({0, k});

    while (!pq.empty()){
        int w = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        if (dijkstra[u] != w){
            continue;
        }

        for (auto nxt : dist[u]){
            if (dijkstra[nxt.second] <= w + nxt.first){
                continue;
            }

            dijkstra[nxt.second] = w + nxt.first;
            pq.push({dijkstra[nxt.second], nxt.second});
        }
    }

    for (int i = 1; i <= v; i++){
        if (dijkstra[i] == INF){
            cout << "INF\n";
        }
        else{
            cout << dijkstra[i] << "\n";
        }
    }

    return 0;
}