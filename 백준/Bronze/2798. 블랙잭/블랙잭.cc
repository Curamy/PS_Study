#include <iostream>
using namespace std;

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    
    int n, m;
    cin >> n >> m;
    int arr[n];

    for (int i = 0; i < n; i++){
        cin >> arr[i];
    }

    int max = 0;

    for (int i = 0; i < n; i++){
        for (int j = i + 1; j < n; j++){
            for (int k = j + 1; k < n; k++){
                int sum = arr[i] + arr[j] + arr[k];
                if (sum <= m && sum > max){
                    max = sum;
                }
            }
        }
    }
    
    cout << max << "\n";
    
    return 0;
}