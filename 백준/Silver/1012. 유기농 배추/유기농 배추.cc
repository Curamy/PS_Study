#include <iostream>
using namespace std;

int m, n, k;
bool map[50][50];

void dfs(int x, int y){
    if (x < 0 || y < 0 || x >= 50 || y >= 50){
        return;
    }
    if (!map[x][y]){
        return;
    }

    map[x][y] = 0;  // 한번 방문했으니 0으로

    dfs(x + 1, y);
    dfs(x, y + 1);
    dfs(x - 1, y);
    dfs(x, y - 1);
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int t;
    cin >> t;
    for (int i = 0; i < t; i++){
        int cnt = 0;
        cin >> m >> n >> k;
        for (int j = 0; j < k; j++){
            int x, y;
            cin >> x >> y;
            map[x][y] = 1;
        }

        for (int a = 0; a < m; a++){
            for (int b = 0; b < n; b++){
                if (map[a][b] == 1){
                    cnt++;
                    dfs(a, b);
                }
            }
        }

        cout << cnt << "\n";
    }

    return 0;
}