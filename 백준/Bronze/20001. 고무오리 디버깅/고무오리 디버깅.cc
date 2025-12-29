#include <iostream>
using namespace std;

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    
    int q_count = 0;
    string s;
    while(1) {
        getline(cin, s);
        if (s == "고무오리 디버깅 시작"){
            continue;
        }
        else if (s == "고무오리 디버깅 끝"){
            break;
        }
        else if (s == "문제"){
            q_count++;
        }
        else if (s == "고무오리"){
            if (q_count == 0){
                q_count += 2;
            }
            else {
                q_count--;
            }
        }
    }

    if (q_count == 0){
        cout << "고무오리야 사랑해\n";
    }
    else {
        cout << "힝구";
    }
    return 0;
}