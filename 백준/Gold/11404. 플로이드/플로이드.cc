#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define INF 99999999
using namespace std;

int n, m;
vector<pair<int, int>> buses[101];
int dijk[101];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n >> m;
    for (int i = 0; i < m; i++){
        int s, e, w;
        cin >> s >> e >> w;
        buses[s].push_back({w, e});
    }

    for (int i = 1; i <= n; i++){
        fill(dijk, dijk + 101, INF);
        while(!pq.empty()){
            pq.pop();
        }

        dijk[i] = 0;
        pq.push({0, i});
        
        while(!pq.empty()){
            int weight = pq.top().first;
            int city = pq.top().second;
            pq.pop();

            if (dijk[city] != weight){
                continue;
            }

            for (auto nxt : buses[city]){
                if (dijk[nxt.second] > weight + nxt.first){
                    dijk[nxt.second] = weight + nxt.first;
                    pq.push({dijk[nxt.second], nxt.second});
                }
            }
        }


        for (int j = 1; j <= n; j++){
            if (dijk[j] == INF){
                cout << "0 ";
            }
            else{
                cout << dijk[j] << " ";
            }
        }
        cout << "\n";
    }

    return 0;
}