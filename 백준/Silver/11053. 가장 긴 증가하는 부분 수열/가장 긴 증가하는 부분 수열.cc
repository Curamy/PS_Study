#include <iostream>
#include <algorithm>
using namespace std;

int n;

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n;
    int arr[n];
    int dp[n];

    for (int i = 0; i < n; i++){
        cin >> arr[i];
        dp[i] = 1;
    }

    for (int i = 0; i < n; i++){
        for (int j = 0; j < i; j++){
            if (arr[j] < arr[i]){
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }

    sort(dp, dp + n);
    cout << dp[n - 1];

    return 0;
}