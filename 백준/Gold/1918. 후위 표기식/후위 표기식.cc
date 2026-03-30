#include <iostream>
#include <string>
#include <cstring>
#include <stack>
using namespace std;

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    
    string str;
    stack<char> s;
    cin >> str;

    for (int i = 0; i < str.length(); i++){
        if (str[i] >= 'A' && str[i] <= 'Z'){        // 문자는 그대로 출력
            cout << str[i];
            continue;
        }

        if (str[i] == '('){
            s.push(str[i]);
            continue;
        }

        if (str[i] == ')'){
            while(s.top() != '('){
                cout << s.top();
                s.pop();
            }
            s.pop();
            continue;
        }

        if (str[i] == '+' || str[i] == '-'){
            while (1){
                if (s.empty() || s.top() == '(') {
                    break;
                }

                cout << s.top();
                s.pop();
            }

            s.push(str[i]);
        }

        if (str[i] == '*' || str[i] == '/'){
            while (!s.empty() && (s.top() == '*' || s.top() == '/')){
                cout << s.top();
                s.pop();
            }

            s.push(str[i]);
        }

    }

    while (!s.empty()){
        cout << s.top();
        s.pop();
    }

    return 0;
}