#include <iostream>
#include <queue>
using namespace std;

long long a, b;
priority_queue<pair<long long, int>> pq;

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> a >> b;
    pq.push({a, 1});

    while(!pq.empty()){
        long long num = pq.top().first;
        int cnt = pq.top().second;
        pq.pop();

        if (num == b){
            cout << cnt;
            return 0;
        }

        if (num * 10 + 1 <= b){
            pq.push({num * 10 + 1, cnt + 1});
        }

        if (num * 2 <= b){
            pq.push({num * 2, cnt + 1});
        }
    }

    cout << -1;

    return 0;
}