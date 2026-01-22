#include <iostream>
#include <queue>
#include <deque>
#include <algorithm>
using namespace std;

int t;

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> t;
    for (int i = 0; i < t; i++){
        string s;
        cin >> s;
        queue<char> q;
        deque<int> nums;

        for (int j = 0; j < s.length(); j++){
            char c = s[j];
            q.push(c);
        }

        bool error = false;
        bool dir = true;    // 정방향-역방향 확인 (매 R마다 reverse하지 않기 위함)
        int n;
        cin >> n;

        cin >> s;
        string tmp;
        for (int j = 1; j < s.length() - 1; j++){
            if (s[j] == ','){   // 쉼표가 나오면 숫자를 배열에 저장
                int num = stoi(tmp);
                nums.push_back(num);
                tmp = "";
            }
            else{   // 쉼표가 나올 때까지 임시 string에 저장
                tmp += s[j];
            }
        }
        if (tmp != ""){ // 마지막 숫자 저장
            nums.push_back(stoi(tmp));
        }

        while(!q.empty()){
            char func = q.front();
            q.pop();
            
            if (func == 'R'){   // 방향 전환
                dir = !dir;
            }

            else {
                if (nums.empty()){
                    cout << "error\n";
                    error = true;
                    break;
                }
                else {
                    if (dir){
                        nums.pop_front();
                    }
                    else{
                        nums.pop_back();
                    }
                }
            }
        }
        
        if (!error){    // 출력
            if (!dir){
                reverse(nums.begin(), nums.end());  // 마지막에 한번만 뒤집어줌
            }

            cout << "[";
            if (nums.size() != 0){
                for (int k = 0; k < nums.size() - 1; k++){
                    cout << nums[k] << ",";
                }
                cout << nums[nums.size() - 1];
            }
            cout << "]\n";
        }
    }

    return 0;
}