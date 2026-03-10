#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int n;
int stc[2][100000];
int dp[2][100000];

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int t;
    cin >> t;
    for (int tc = 0; tc < t; tc++){
        cin >> n;
        memset(dp, 0, sizeof(dp));
        for (int i = 0; i < n; i++){
            cin >> stc[0][i];
        }
        for (int i = 0; i < n; i++){
            cin >> stc[1][i];
        }
        dp[0][0] = stc[0][0];
        dp[1][0] = stc[1][0];
        dp[0][1] = stc[0][1] + stc[1][0];
        dp[1][1] = stc[0][0] + stc[1][1];

        for (int i = 2; i < n; i++){
            dp[0][i] = max(dp[1][i - 2], dp[1][i - 1]) + stc[0][i];
            dp[1][i] = max(dp[0][i - 2], dp[0][i - 1]) + stc[1][i];
        }

        cout << max(dp[0][n - 1], dp[1][n - 1]) << '\n';
    }

    return 0;
}