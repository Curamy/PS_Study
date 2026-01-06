// DFS
#include <iostream>
#include <vector>
#define MAX 101
using namespace std;

int n, m;
int cnt = 0;
vector<int> G[MAX];    // Graph 연결 관계 -> 벡터 타입 배열
bool visited[MAX] = {0, };

void DFS(int s){
    visited[s] = true;
    for (int i = 0; i < G[s].size(); i++){
        int k = G[s][i];
        if (!visited[k]){
            cnt++;
            DFS(k);
        }
    }
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n;
    cin >> m;

    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    DFS(1);
    cout << cnt;

    return 0;
}

// BFS
// #include <iostream>
// #include <queue>
// #define MAX 101
// using namespace std;

// int n, m;
// int cnt = 0;
// queue<int> Q;       // BFS -> QUEUE 이용
// int G[MAX][MAX];    // Graph 연결 관계
// bool visited[MAX] = {0, };

// void BFS(int s){
//     Q.push(s);
//     visited[s] = true;

//     while(!Q.empty()){
//         s = Q.front();
//         Q.pop();

//         for (int i = 1; i <= n; i++){
//             if (G[s][i] == 1 && visited[i] == 0){
//                 Q.push(i);
//                 visited[i] = true;
//                 cnt++;
//             }
//         }
//     }
// }

// int main() {
//     cin.tie(NULL);
//     cout.tie(NULL);
//     ios_base::sync_with_stdio(false);

//     cin >> n;
//     cin >> m;

//     for(int i = 0; i < m; i++){
//         int a, b;
//         cin >> a >> b;
//         G[a][b] = 1;
//         G[b][a] = 1;
//     }

//     BFS(1);
//     cout << cnt;

//     return 0;
// }