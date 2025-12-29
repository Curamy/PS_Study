#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstdlib>
#include <stdexcept>
#include <limits>

using namespace std;

int main(){
    int playtime = 0;
    scanf("%d", &playtime);
    for(int i=0; i<playtime; i++){
        int V, E, start;
    vector <pair <int, int> > edges[10001];
    scanf("%d", &V);
    scanf("%d", &E);
    scanf("%d", &start);
    for(int i=0; i<E; i++){
        int vA, vB;
        int wt;
        scanf("%d %d %d", &vB, &vA, &wt);
        vA--;
        vB--;
        edges[vA].push_back(make_pair(vB, wt));
    }
    
    bool *visit = new bool [V];
    int *previous = new int [V];
    int *distance = new int [V];

    for(int i=0; i<V; i++){
        visit[i] = false;
        previous[i] = -1;
        distance[i] = std::numeric_limits<int>::max() / (int)2;
    }

    start--;
    distance[start] = 0;
    previous[start] = start;

    priority_queue< pair<int, int>, vector< pair<int, int> >, greater< pair<int, int> > > pq;
    pq.push( make_pair( (int)0, start));

    while(1){
        if(pq.empty())
            break;
        
        pair<int, int> x = pq.top();
        pq.pop();
        if(visit[x.second])
            continue;
        visit[x.second] = true;

        for(int i=0; i<edges[x.second].size(); i++){
            int idx = edges[x.second][i].first;
            int weight = edges[x.second][i].second;

            if(!visit[idx] && distance[idx] > distance[x.second] + weight){
                pq.push( make_pair(distance[x.second] + weight, idx));
                previous[idx] = x.second;
                distance[idx] = distance[x.second] + weight;
            }
        }
    }
    int count = 0;
    int result = 0;
    for(int i=0; i<V; i++){
        if(visit[i]){
            count++;
            if(distance[i] > result){
                result = distance[i];
            }
        }
    }
    printf("%d %d\n", count, result);

    delete[] visit;
    delete[] previous;
    delete[] distance;

    }
    return 0;
}