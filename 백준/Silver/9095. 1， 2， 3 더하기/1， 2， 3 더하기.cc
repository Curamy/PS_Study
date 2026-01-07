#include <iostream>
using namespace std;

int dp[11] = {0, };

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;

    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 4;

    for (int i = 4; i <= 10; i++){
        if (i >= 3){
            dp[i] += dp[i - 3];
        }
        if (i >= 2){
            dp[i] += dp[i - 2];
        }
        dp[i] += dp[i - 1];
    }

    for (int i = 0; i < n; i++){
        int num;
        cin >> num;
        cout << dp[num] << "\n";
    }

    return 0;
}