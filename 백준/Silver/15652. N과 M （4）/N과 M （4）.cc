#include <iostream>
using namespace std;

int n, m;
int arr[9];

void func(int k){
    if (k == m){
        for (int i = 0; i < m; i++){
            cout << arr[i] << " ";
        }
        cout << "\n";
        return;
    }

    for (int i = 1; i <= n; i++){
        if (k != 0 && i < arr[k - 1]){
            continue;
        }

        arr[k] = i;
        func(k + 1);
    }
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n >> m;
    fill(arr, arr + 9, 0);
    func(0);

    return 0;
}