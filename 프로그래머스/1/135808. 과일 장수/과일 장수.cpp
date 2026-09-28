#include <string>
#include <vector>
#include <string.h>
#include <iostream>

using namespace std;

int solution(int k, int m, vector<int> score) {
    int answer = 0;
    
    int n = score.size();    
    int nums[10];
    memset(nums, 0, sizeof(nums));
    for (int i = 0; i < n; i++){
        nums[score[i]]++;
    }
    
    for (int p = k; p > 0; p--){
        int appleCnt = nums[p];
        int boxCnt = 0;
        
        if (appleCnt >= m){
            boxCnt += (appleCnt / m);
            appleCnt -= (boxCnt * m);
        }
        
        answer += (boxCnt * p * m);
        nums[p - 1] += appleCnt;
    }
    
    return answer;
}