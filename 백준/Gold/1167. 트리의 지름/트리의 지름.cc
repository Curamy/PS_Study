// 임의의 정점(1번 노드)에서 가장 먼 정점 A를 찾기
// 정점 A에서 가장 먼 정점 B를 찾기
// A와 B의 거리가 트리의 지름이 된다

#include <iostream>
#include <algorithm>
#include <vector>
#define INF 1e9
using namespace std;

int v;
vector<pair<int, int>> pairs[100001];
bool visited[100001];
int max_dist;
int far_node;

void dfs(int node, int dist){
    if (dist > max_dist){
        max_dist = dist;
        far_node = node;
    }

    for (auto nxt : pairs[node]){
        if (!visited[nxt.second]){
            visited[nxt.second] = true;
            dfs(nxt.second, dist + nxt.first);
        }
    }
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    
    cin >> v;

    for (int i = 1; i <= v; i++){
        int ver;
        cin >> ver;

        int node, weight;
        while(1){
            cin >> node;
            if (node == -1){
                break;
            }
            cin >> weight;

            pairs[ver].push_back({weight, node});
        }
    }

    fill(visited, visited + 100001, 0);
    max_dist = 0;

    visited[1] = true;
    dfs(1, 0);

    fill(visited, visited + 100001, 0);
    max_dist = 0;

    visited[far_node] = true;
    dfs(far_node, 0);

    cout << max_dist;
    
    return 0;
}