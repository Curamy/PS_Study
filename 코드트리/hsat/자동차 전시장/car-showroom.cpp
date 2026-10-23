#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, m, k;
vector<int> start_points;
vector<int> routes[100001];
vector<vector<int>> result;

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n >> m >> k;

    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        routes[x].push_back(y);
    }

    start_points.resize(k);
    for (int i = 0; i < k; i++) {
        cin >> start_points[i];
    }

    for (auto sp : start_points){
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        int dijkstra[100001];
        for (int i = 1; i <= n; i++){
            dijkstra[i] = 999999;
        }

        dijkstra[sp] = 0;
        pq.push({0, sp});

        while(!pq.empty()){
            int dist = pq.top().first;
            int node = pq.top().second;
            pq.pop();


            if (dist != dijkstra[node]){
                continue;
            }

            for (auto nxt : routes[node]){
                if (dist + 1 < dijkstra[nxt]){
                    pq.push({dist + 1, nxt});
                    dijkstra[nxt] = dist + 1;
                }
            }
        }

        vector<int> this_result;
        for (int j = 1; j <= n; j++){
            this_result.push_back(dijkstra[j]);
        }
        result.push_back(this_result);
    }

    int answer = 999999;
    for (int i = 0; i < n; i++){
        int local_max = -1;
        for (int j = 0; j < k; j++){
            if (local_max < result[j][i]){
                local_max = result[j][i];
            }
        }
        if (answer > local_max){
            answer = local_max;
        }
    }

    if (answer == 999999){
        cout << -1;
        return 0;
    }

    cout << answer;
    return 0;
}
