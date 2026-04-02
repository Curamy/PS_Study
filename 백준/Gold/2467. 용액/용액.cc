#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
vector<int> minus_sol;
vector<int> plus_sol;
int ans;
int ans_nums[2];

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n;
    ans = 2000000000;

    for (int i = 0; i < n; i++){
        int num;
        cin >> num;
        if (num < 0){
            minus_sol.push_back(num * -1);
        }
        else {
            plus_sol.push_back(num);
        }
    }

    reverse(minus_sol.begin(), minus_sol.end());

    if (minus_sol.size() > 1){
        ans = minus_sol[0] + minus_sol[1];
        ans_nums[0] = minus_sol[1] * -1;
        ans_nums[1] = minus_sol[0] * -1;
    }

    if (plus_sol.size() > 1){
        if (plus_sol[0] + plus_sol[1] < ans){
            ans = plus_sol[0] + plus_sol[1];
            ans_nums[0] = plus_sol[0];
            ans_nums[1] = plus_sol[1];
        }
    }

    if (minus_sol.size() < plus_sol.size()){
        for (auto minus_val : minus_sol){
            int comp = lower_bound(plus_sol.begin(), plus_sol.end(), minus_val) - plus_sol.begin();
            if (comp == 0) {
                int cur_sum = plus_sol[0] - minus_val;
                if (cur_sum < ans){
                    ans = cur_sum;
                    ans_nums[0] = minus_val * -1;
                    ans_nums[1] = plus_sol[0];
                }
            }

            else if (comp == plus_sol.size()){
                int cur_sum = minus_val - plus_sol[comp - 1];
                if (cur_sum < ans){
                    ans = cur_sum;
                    ans_nums[0] = minus_val * -1;
                    ans_nums[1] = plus_sol[comp - 1];
                }
            }

            else {
                int cur_sum1 = plus_sol[comp] - minus_val;
                int cur_sum2 = minus_val - plus_sol[comp - 1];

                if (cur_sum1 < cur_sum2 && cur_sum1 < ans){
                    ans = cur_sum1;
                    ans_nums[0] = minus_val * -1;
                    ans_nums[1] = plus_sol[comp];
                }

                if (cur_sum2 < cur_sum1 && cur_sum2 < ans){
                    ans = cur_sum2;
                    ans_nums[0] = minus_val * -1;
                    ans_nums[1] = plus_sol[comp - 1];
                }
            }
        }
    }
    else {
        for (auto plus_val : plus_sol){
            int comp = lower_bound(minus_sol.begin(), minus_sol.end(), plus_val) - minus_sol.begin();
            if (comp == 0) {
                int cur_sum = minus_sol[0] - plus_val;
                if (cur_sum < ans){
                    ans = cur_sum;
                    ans_nums[0] = minus_sol[0] * -1;
                    ans_nums[1] = plus_val;
                }
            }

            else if (comp == minus_sol.size()){
                int cur_sum = plus_val - minus_sol[comp - 1];
                if (cur_sum < ans){
                    ans = cur_sum;
                    ans_nums[0] = minus_sol[comp - 1] * -1;
                    ans_nums[1] = plus_val;
                }
            }

            else {
                int cur_sum1 = minus_sol[comp] - plus_val;
                int cur_sum2 = plus_val - minus_sol[comp - 1];

                if (cur_sum1 < cur_sum2 && cur_sum1 < ans){
                    ans = cur_sum1;
                    ans_nums[0] = minus_sol[comp] * -1;
                    ans_nums[1] = plus_val;
                }

                if (cur_sum2 <= cur_sum1 && cur_sum2 < ans){
                    ans = cur_sum2;
                    ans_nums[0] = minus_sol[comp - 1] * -1;
                    ans_nums[1] = plus_val;
                }
            }
        }
    }

    cout << ans_nums[0] << " " << ans_nums[1];

    return 0;
}