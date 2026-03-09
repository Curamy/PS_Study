#include <iostream>
#include <algorithm>

using namespace std;

int n;
int tri[500][500];
int dp[500][500];
int ans;

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    ans = 0;
    cin >> n;
    for (int i = 0; i < n; i++){
        for (int j = 0; j <= i; j++){
            int num;
            cin >> num;
            tri[i][j] = num;
        }
    }

    dp[0][0] = tri[0][0];
    dp[1][0] = tri[0][0] + tri[1][0];
    dp[1][1] = tri[0][0] + tri[1][1];

    for (int i = 2; i < n; i++){
        dp[i][0] = dp[i - 1][0] + tri[i][0];

        for (int j = 1; j < i; j++){
            dp[i][j] = max(dp[i - 1][j - 1] + tri[i][j], dp[i - 1][j] + tri[i][j]);
        }

        dp[i][i] = dp[i - 1][i - 1] + tri[i][i];
    }

    for (int i = 0; i < n; i++){
        if (dp[n - 1][i] > ans){
            ans = dp[n - 1][i];
        }
    }
    cout << ans;
    
    return 0;
}