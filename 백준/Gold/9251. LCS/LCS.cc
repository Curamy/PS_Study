#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
using namespace std;

int dp[1001][1001];     // 첫번째 문자열의 i번째 글자까지 + 두번째 문자열의 j번재 글자까지의 LCS 길이

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    string str1, str2;
    cin >> str1 >> str2;
    int n = str1.length();
    int m = str2.length();

    memset(dp, 0, sizeof(dp));

    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            if (str1[i - 1] == str2[j - 1]){
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else {
                dp[i][j] = max({dp[i - 1][j - 1], dp[i - 1][j], dp[i][j - 1]});
            }
        }
    }

    cout << dp[n][m];
    return 0;
}