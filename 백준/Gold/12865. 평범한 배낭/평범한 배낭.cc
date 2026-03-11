// 배낭 문제, DP

#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int n, k;
int dp[100001];     // 버틸 수 있는 무게가 i일 때 넣을 수 있는 가치의 최댓값 저장

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n >> k;
    memset(dp, 0, sizeof(dp));

    for (int i = 0; i < n; i++){
        int w, v;
        cin >> w >> v;
        
        for (int j = k; j >= w; j--){
            dp[j] = max(dp[j], dp[j - w] + v);
        }
    }

    cout << dp[k];
    
    return 0;
}