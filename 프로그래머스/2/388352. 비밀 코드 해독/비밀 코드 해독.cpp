#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int n, vector<vector<int>> q, vector<int> ans) {
    int check_arr[5];
    int answer = 0;
    
    for (int first = 1; first <= n - 4; first++){
        check_arr[0] = first;
        for (int second = first + 1; second <= n - 3; second++){
            check_arr[1] = second;
            for (int third = second + 1; third <= n - 2; third++){
                check_arr[2] = third;
                for (int fourth = third + 1; fourth <= n - 1; fourth++){
                    check_arr[3] = fourth;
                    for (int fifth = fourth + 1; fifth <= n; fifth++){
                        check_arr[4] = fifth;
                        bool is_okay = true;
                        
                        for (int i = 0; i < ans.size(); i++){
                            int inc_cnt = 0;
                            
                            for (auto num : q[i]){
                                if (find(check_arr, check_arr + 5, num) != check_arr + 5){
                                    inc_cnt++;
                                }
                            }
                            
                            if (inc_cnt != ans[i]){
                                is_okay = false;
                                break;
                            }
                        }
                        
                        if (is_okay){
                            answer++;
                        }
                    }
                }
            }
        }
    }
    
    return answer;
}