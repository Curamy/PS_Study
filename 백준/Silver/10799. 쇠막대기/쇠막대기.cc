#include <iostream>
#include <stack>
#include <string>
#include <cstring>
using namespace std;

stack<char> s;

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    string str;
    cin >> str;

    int piece = 0;
    
    for (int i = 0; i < str.length(); i++){
        if (str[i] == '('){
            if (str[i + 1] == ')'){     // 레이저
                i++;
                piece += s.size();
                continue;
            }
            else{
                s.push(str[i]);
                piece++;
            }
        }

        if (str[i] == ')'){     // 막대기 끝
            s.pop();
        }
    }

    cout << piece;
    
    return 0;
}