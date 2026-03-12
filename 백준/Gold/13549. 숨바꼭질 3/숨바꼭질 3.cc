#include <iostream>
#include <queue>
#include <algorithm>
#define INF 1000000
using namespace std;

int n, k;
int dist[100001];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n >> k;
    fill(dist, dist + 100001, INF);

    dist[n] = 0;
    pq.push({0, n});

    while(!pq.empty()){
        int d = pq.top().first;
        int p = pq.top().second;
        pq.pop();

        if (p == k){
            cout << dist[k];
            break;
        }

        if (dist[p] != d){
            continue;
        }

        if (p != 0){
            for (int i = p; i <= 100000; i *= 2){
                if (dist[i] <= d){
                    continue;
                }
                dist[i] = d;
                pq.push({dist[i], i});
            }
        }

        if (p > 0 && dist[p - 1] > d + 1){
            dist[p - 1] = d + 1;
            pq.push({dist[p - 1], (p - 1)});
        }

        if (p < 100000 && dist[p + 1] > d + 1){
            dist[p + 1] = d + 1;
            pq.push({dist[p + 1], (p + 1)});
        }
    }

    return 0;
}