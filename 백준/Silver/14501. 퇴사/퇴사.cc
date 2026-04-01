#include <iostream>
#include <algorithm>
using namespace std;

struct Schedule {
    int length;
    int income;
};

int n;
int dp[17];
Schedule schedule[16];

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    
    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> schedule[i].length >> schedule[i].income;
    }
    fill(dp, dp + 17, 0);

    for (int i = n; i >= 1; i--){
        if (i + schedule[i].length > n + 1){
            dp[i] = dp[i + 1];
            continue;
        }

        dp[i] = dp[i] + schedule[i].income + dp[i + schedule[i].length];
        for (int j = i; j < i + schedule[i].length; j++){
            if (dp[j] > dp[i]){
                dp[i] = dp[j];
            }
        }
    }

    int ans = 0;
    for (int i = 1; i <= n; i++){
        if (dp[i] > ans){
            ans = dp[i];
        }
    }

    cout << ans;

    return 0;
}