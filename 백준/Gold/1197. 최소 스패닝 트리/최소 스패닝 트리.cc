#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>

using namespace std;

int main(int argc, char **argv){
    int V, E;
    vector <pair <int, int> > edges[10001];
    scanf("%d", &V);
    scanf("%d", &E);
    for(int i=0; i<E; i++){
        int vA, vB;
        int wt;
        scanf("%d %d %d", &vA, &vB, &wt);
        vA--;
        vB--;
        edges[vA].push_back(make_pair(vB, wt));
        edges[vB].push_back(make_pair(vA, wt));
    }

    bool *visit = new bool [V];
    int *parent = new int [V];
    int *distance = new int [V];

    for(int i=0; i<V; i++){
        visit[i] = false;
        parent[i] = -1;
        distance[i] = 99999999;
    }

    int rootidx = 0;
    distance[rootidx] = 0;
    parent[rootidx] = 0;

    priority_queue< pair<int, int>, vector< pair<int, int> >, greater< pair<int, int> > > pq;
    pq.push( make_pair( (int)0, rootidx));

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

            if(!visit[idx] && weight < distance[idx]){
                pq.push( make_pair(weight, idx));
                parent[idx] = x.second;
                distance[idx] = weight;
            }
        }
    }

    long long answer = 0;
    for(int i=0; i<V; i++){
        answer += distance[i];
    }

    delete[] visit;
    delete[] parent;
    delete[] distance;

    printf("%lld\n" , answer);
    
    return 0;
}