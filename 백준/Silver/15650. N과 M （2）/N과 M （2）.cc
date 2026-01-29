#include <iostream>
using namespace std;

int n, m;
bool visited[9];

void dfs(int i, int left){
    if (left == 1){
        for (int i = 1; i <= n; i++){
            if(visited[i] == true){
                cout << i << " ";
            }
        }
        cout << "\n";
        visited[i] = false;
        return;
    }

    for (int j = i + 1; j <= n; j++){
        visited[j] = true;
        dfs(j, left - 1);
        visited[j] = false;
    }
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n >> m;

    for (int i = 1; i <= n - m + 1; i++){
        visited[i] = true;
        dfs(i, m);
        visited[i] = false;
    }

    return 0;
}