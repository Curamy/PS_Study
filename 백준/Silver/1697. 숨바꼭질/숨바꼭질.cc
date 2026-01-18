#include <iostream>
#include <queue>
using namespace std;

// bfs

int n, k;
queue<pair<int, int>> q;
bool visited[100001];

void bfs(int n){
    q.push(make_pair(n, 0));
    visited[n] = true;

    while(!q.empty()){
        int cur = q.front().first;
        int cnt = q.front().second;
        q.pop();

        if (cur == k){
            cout << cnt;
            return;
        }

        if (cur - 1 >= 0 && visited[cur - 1] == 0){
            visited[cur - 1] = true;
            q.push(make_pair(cur - 1, cnt + 1));
        }
        if (cur + 1 < 100001 && visited[cur + 1] == 0){
            visited[cur + 1] = true;
            q.push(make_pair(cur + 1, cnt + 1));
        }
        if (cur * 2 < 100001 && visited[cur * 2] == 0){
            visited[cur * 2] = true;
            q.push(make_pair(cur * 2, cnt + 1));
        }
    }
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n >> k;

    bfs(n);

    return 0;
}