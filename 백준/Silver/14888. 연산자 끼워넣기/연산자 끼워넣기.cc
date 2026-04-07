#include <iostream>
using namespace std;

int n;
int max_ans;
int min_ans;
int nums[11];
int oper[4];        // 0: +, 1: -, 2: *, 3: /

void calc(int d, int val){
    if (d == n){
        if (val > max_ans){
            max_ans = val;
        }
        if (val < min_ans){
            min_ans = val;
        }
        return;
    }

    for (int i = 0; i < 4; i++){
        if (oper[i] == 0){
            continue;
        }

        int nextVal;
        if (i == 0){
            nextVal = val + nums[d];
        }
        else if (i == 1){
            nextVal = val - nums[d];
        }
        
        else if (i == 2){
            nextVal = val * nums[d];
        }
        
        else if (i == 3){
            nextVal = val / nums[d];
        }

        oper[i]--;
        calc(d + 1, nextVal);
        oper[i]++;
    }
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    
    max_ans = -1000000001;
    min_ans = 1000000001;

    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> nums[i];
    }
    for (int i = 0; i < 4; i++){
        cin >> oper[i];
    }

    calc(1, nums[0]);

    cout << max_ans << "\n" << min_ans;
    
    return 0;
}