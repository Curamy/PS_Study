#include <iostream>
#include <string>
#include <deque>
using namespace std;

int k;
deque<int> gear[5];

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    
    for (int i = 1; i <= 4; i++){
        string nums;
        cin >> nums;
        for (int j = 0; j < 8; j++){
            int num = nums[j] - '0';
            gear[i].push_back(num);
        }
    }

    cin >> k;

    for (int _k = 0; _k < k; _k++){
        int target_gear, rotate_way[5];
        cin >> target_gear >> rotate_way[target_gear];

        int left = target_gear;
        int right = target_gear;

        while(left > 1){
            if (rotate_way[left] == 0){
                rotate_way[left - 1] = 0;
                left--;
                continue;
            }

            if (gear[left][6] == gear[left - 1][2]){
                rotate_way[left - 1] = 0;
            }
            else {
                rotate_way[left - 1] = rotate_way[left] * -1;
            }

            left--;
        }

        while(right < 4){
            if (rotate_way[right] == 0){
                rotate_way[right + 1] = 0;
                right++;
                continue;
            }
            
            if (gear[right][2] == gear[right + 1][6]){
                rotate_way[right + 1] = 0;
            }
            else {
                rotate_way[right + 1] = rotate_way[right] * -1;
            }

            right++;
        }

        for (int i = 1; i <= 4; i++){
            if (rotate_way[i] == 0){
                continue;
            }

            else if (rotate_way[i] == 1){       // 시계 방향
                int num = gear[i][7];
                gear[i].pop_back();
                gear[i].push_front(num);
            }

            else if (rotate_way[i] == -1){       // 반시계 방향
                int num = gear[i][0];
                gear[i].pop_front();
                gear[i].push_back(num);
            }
        }
    }

    int ans = 0;
    if (gear[1][0] == 1){
        ans += 1;
    }
    if (gear[2][0] == 1){
        ans += 2;
    }
    if (gear[3][0] == 1){
        ans += 4;
    }
    if (gear[4][0] == 1){
        ans += 8;
    }

    cout << ans;
    
    return 0;
}