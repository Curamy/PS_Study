#include <string>
#include <vector>
#include <iostream>
#include <string.h>

using namespace std;

int board[1024][1024];
bool packed[1024][1024];

vector<int> solution(vector<vector<int>> arr) {
    memset(board, 0, sizeof(board));
    memset(packed, 0, sizeof(packed));
    
    vector<int> answer;
    int cnt0 = 0;
    int cnt1 = 0;
    
    int size = arr.size();
    for (int i = 0; i < arr.size(); i++){
        for (int j = 0; j < arr.size(); j++){
            board[i][j] = arr[i][j];
            if (arr[i][j] == 0){
                cnt0++;
            }
            else {
                cnt1++;
            }
        }
    }
    
    if (cnt0 == 0){
        cnt1 = 1;
        answer.push_back(cnt0);
        answer.push_back(cnt1);
        return answer;
    }
    if (cnt1 == 0) {
        cnt0 = 1;
        answer.push_back(cnt0);
        answer.push_back(cnt1);
        return answer;
    }
    
    int n = arr.size() / 2;
    while (n > 1){
        for (int i = 0; i < arr.size(); i+=n){
            for (int j = 0; j < arr.size(); j+=n){
                if (packed[i][j]){
                    continue;
                }
                
                bool is_zero = true;
                bool can_pack = true;
                if (board[i][j] == 0){
                    is_zero = true;
                }
                else {
                    is_zero = false;
                }
                
                for (int k = 0; k < n; k++){
                    if (!can_pack){
                        break;
                    }
                    for (int l = 0; l < n; l++){
                        if (!can_pack){
                            break;
                        }
                        if (is_zero && board[i + k][j + l] == 1){
                            can_pack = false;
                            break;
                        }
                        if (!is_zero && board[i + k][j + l] == 0){
                            can_pack = false;
                            break;
                        }
                    }
                }
                
                if (can_pack){
                    for (int k = 0; k < n; k++){
                        for (int l = 0; l < n; l++){
                            packed[i + k][j + l] = true;
                        }
                    }
                    if (is_zero){
                        cnt0 = cnt0 - (n * n) + 1;
                    }
                    else{
                        cnt1 = cnt1 - (n * n) + 1;
                    }
                }
                
            }
        }
        
        n /= 2;
    }
    
    answer.push_back(cnt0);
    answer.push_back(cnt1);
    return answer;
}