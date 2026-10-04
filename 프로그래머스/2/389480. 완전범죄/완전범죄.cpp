#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int dp[120];
int next_dp[120];

int solution(vector<vector<int>> info, int n, int m) {
    int answer = n;
    
    fill(dp, dp + n, m);
    fill(next_dp, next_dp + n, m);
    
    if (info[0][0] < n){
        next_dp[info[0][0]] = 0;
    }
    if (info[0][1] < m){
        next_dp[0] = info[0][1];
    }
    
    for (int i = 1; i < info.size(); i++){
        copy(next_dp, next_dp + n, dp);
        fill(next_dp, next_dp + n, m);
        
        for (int a = 0; a < n; a++){
            if (dp[a] == m){
                continue;
            }
            
            if (a + info[i][0] < n){
                if (dp[a] < next_dp[a + info[i][0]]){
                    next_dp[a + info[i][0]] = dp[a];
                }
            }
            
            if (dp[a] + info[i][1] < next_dp[a]){
                next_dp[a] = dp[a] + info[i][1];
            }
        }
    }
    
    for (int a = 0; a < n; a++){
        if (next_dp[a] != m){
            return a;
        }
    }
    
    return -1;
}