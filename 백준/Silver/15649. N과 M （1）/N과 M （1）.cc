// 백트래킹

#include <iostream>
using namespace std;

int n, m;
int arr[9];
bool visited[9];

void func(int k){
    if (k == m){
        for (int i = 0; i < m; i++){
            cout << arr[i] << " ";
        }
        cout << "\n";
        return;
    }

    for (int i = 1; i <= n; i++){
        if(visited[i]){
            continue;
        }

        arr[k++] = i;
        visited[i] = true;
        func(k);
        k--;
        visited[i] = false;
    }
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n >> m;
    func(0);

    return 0;
}