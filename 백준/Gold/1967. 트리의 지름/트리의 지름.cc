#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n;
vector<pair<int, int>> tree[10001];
int ans;

int searchMaxLeaf(int node){
    int maxDist[2] = {0, 0};
    priority_queue<pair<int, int>> pq;
    int curMax = 0;

    for (auto nxt : tree[node]){
        curMax = 0;
        int curWeight = nxt.first;
        int curChild = nxt.second;
        pq.push({curWeight, curChild});

        while (!pq.empty()){
            int curSum = pq.top().first;
            int curNode = pq.top().second;
            pq.pop();

            if (tree[curNode].empty()){
                if (curSum > curMax) {
                    curMax = curSum;
                }
                continue;
            }

            for (auto child : tree[curNode]){
                pq.push({curSum + child.first, child.second});
            }
        }

        if (maxDist[1] < curMax){
            if (maxDist[0] < curMax) {
                maxDist[1] = maxDist[0];
                maxDist[0] = curMax;
            }
            else {
                maxDist[1] = curMax;
            }

            continue;
        }
    }

    return maxDist[0] + maxDist[1];
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n;
    for (int i = 0; i < n - 1; i++){
        int pn, cn, w;
        cin >> pn >> cn >> w;
        
        tree[pn].push_back({w, cn});
    }

    ans = 0;

    for (int i = 1; i <= n; i++){
        if (tree[i].empty()){
            continue;
        }

        if (searchMaxLeaf(i) > ans){
            ans = searchMaxLeaf(i);
        }
    }

    cout << ans;

    return 0;
}