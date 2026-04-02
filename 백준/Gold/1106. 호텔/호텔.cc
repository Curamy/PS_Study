#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int c, n;
vector<pair<int, int>> ads;
int cost[1001];

void dfs(int cur_customer, int cur_cost){
    for (auto ad : ads){
        if (cur_customer + ad.second >= c){
            if (cost[c] > cur_cost + ad.first){
                cost[c] = cur_cost + ad.first;
            }
            continue;
        }

        if (cost[cur_customer + ad.second] > cur_cost + ad.first){
            cost[cur_customer + ad.second] = cur_cost + ad.first;
            dfs(cur_customer + ad.second, cur_cost + ad.first);
        }
    }
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    fill(cost, cost + 1001, 100000);
    cin >> c >> n;
    for (int i = 0; i < n; i++){
        int city_money, city_get;
        cin >> city_money >> city_get;
        ads.push_back({city_money, city_get});
    }

    dfs(0, 0);

    cout << cost[c];

    return 0;
}