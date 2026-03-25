#include <iostream>
#include <stack>
#include <string>
#include <cstring>
using namespace std;

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    while(1){
        string str;
        getline(cin, str);
        if (str == "."){
            break;
        }

        stack<char> s;
        bool okay = true;

        for (int i = 0; i < str.length(); i++){
            if (str[i] == '(' || str[i] == '['){
                s.push(str[i]);
            }

            if (str[i] == ')'){
                if (s.empty() || s.top() != '('){
                    okay = false;
                    break;
                }
                else {
                    s.pop();
                }
            }

            if (str[i] == ']'){
                if (s.empty() || s.top() != '['){
                    okay = false;
                    break;
                }
                else {
                    s.pop();
                }
            }
        }

        if (!s.empty()){
            okay = false;
        }

        if (okay){
            cout << "yes\n";
        }
        else {
            cout << "no\n";
        }
    }

    return 0;
}