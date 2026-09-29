#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>

using namespace std;

#define INF 99999999

vector<pair<int, int>> dist[201];
int dijkstra_s[201];
int dijkstra_a[201];
int dijkstra_b[201];
// s -> x -> a + s -> x -> b가 최소가 되는 x를 찾아야 함.
// 따라서 a와 b부터 다른 노드까지의 거리를 계산하는 각각의 다익스트라를 구해야 함

int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    fill(dijkstra_s, dijkstra_s + 201, INF);
    fill(dijkstra_a, dijkstra_a + 201, INF);
    fill(dijkstra_b, dijkstra_b + 201, INF);
    
    for (auto fare : fares){
        dist[fare[0]].push_back({fare[2], fare[1]});
        dist[fare[1]].push_back({fare[2], fare[0]});
    }
    
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    dijkstra_s[s] = 0;
    pq.push({0, s});
    
    while(!pq.empty()){
        int w = pq.top().first;
        int u = pq.top().second;
        pq.pop();
        
        if (dijkstra_s[u] != w){
            continue;
        }
        
        for (auto nxt : dist[u]){
            if (dijkstra_s[nxt.second] <= w + nxt.first){
                continue;
            }
            
            dijkstra_s[nxt.second] = w + nxt.first;
            pq.push({dijkstra_s[nxt.second], nxt.second});
        }
    }
    
    dijkstra_a[a] = 0;
    pq.push({0, a});
    
    while(!pq.empty()){
        int w = pq.top().first;
        int u = pq.top().second;
        pq.pop();
        
        if (dijkstra_a[u] != w){
            continue;
        }
        
        for (auto nxt : dist[u]){
            if (dijkstra_a[nxt.second] <= w + nxt.first){
                continue;
            }
            
            dijkstra_a[nxt.second] = w + nxt.first;
            pq.push({dijkstra_a[nxt.second], nxt.second});
        }
    }

    dijkstra_b[b] = 0;
    pq.push({0, b});
    
    while(!pq.empty()){
        int w = pq.top().first;
        int u = pq.top().second;
        pq.pop();
        
        if (dijkstra_b[u] != w){
            continue;
        }
        
        for (auto nxt : dist[u]){
            if (dijkstra_b[nxt.second] <= w + nxt.first){
                continue;
            }
            
            dijkstra_b[nxt.second] = w + nxt.first;
            pq.push({dijkstra_b[nxt.second], nxt.second});
        }
    }
    
    int answer = INF;
    for (int i = 1; i <= n; i++){
        if (dijkstra_s[i] + dijkstra_a[i] + dijkstra_b[i] < answer){
            answer = dijkstra_s[i] + dijkstra_a[i] + dijkstra_b[i];
        }
    }
    
    return answer;
}