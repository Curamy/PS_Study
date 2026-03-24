#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#define INF 999999
using namespace std;

int n, m, x;
vector<pair<int, int>> forward_roads[1001];
vector<pair<int, int>> reverse_roads[1001];
priority_queue<pair<int, int>> pq;
int forward_dijk[1001];
int reverse_dijk[1001];

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    
    cin >> n >> m >> x;
    fill(forward_dijk, forward_dijk + 1001, INF);
    fill(reverse_dijk, reverse_dijk + 1001, INF);

    for (int i = 0; i < m; i++){
        int s, e, w;
        cin >> s >> e >> w;

        forward_roads[s].push_back({w, e});
        reverse_roads[e].push_back({w, s});
    }

    forward_dijk[x] = 0;
    pq.push({0, x});

    while(!pq.empty()){
        int weight = pq.top().first;
        int town = pq.top().second;
        pq.pop();
        
        if (forward_dijk[town] != weight){
            continue;
        }

        for (auto nxt : forward_roads[town]){
            if (forward_dijk[nxt.second] > weight + nxt.first){
                forward_dijk[nxt.second] = weight + nxt.first;
                pq.push({forward_dijk[nxt.second], nxt.second});
            }
        }
    }

    while(!pq.empty()){
        pq.pop();
    }

    reverse_dijk[x] = 0;
    pq.push({0, x});

    while(!pq.empty()){
        int weight = pq.top().first;
        int town = pq.top().second;
        pq.pop();
        
        if (reverse_dijk[town] != weight){
            continue;
        }

        for (auto nxt : reverse_roads[town]){
            if (reverse_dijk[nxt.second] > weight + nxt.first){
                reverse_dijk[nxt.second] = weight + nxt.first;
                pq.push({reverse_dijk[nxt.second], nxt.second});
            }
        }
    }

    int ans = 0;

    for (int i = 1; i <= n; i++){
        int time = forward_dijk[i] + reverse_dijk[i];
        if (time > ans){
            ans = time;
        }
    }

    cout << ans;

    return 0;
}