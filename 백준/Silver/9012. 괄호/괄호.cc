#include <iostream>
#include <string>
using namespace std;

int check(string str){
    int p = 0;
    for (int j=0; j<str.length(); j++){
        if (str[j] == '('){
            p++;
        }
        else if (str[j] == ')'){
            p--;
        }

        if (p < 0){
            return 0;
        }
    }

    if(p == 0){
        return 1;
    }
    else{
        return 0;
    }
}

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    for (int i=0; i<n; i++){
        string str;
        cin >> str;
        if(check(str) == 1){
            cout << "YES\n";
        }
        else{
            cout << "NO\n";
        }
    }

    return 0;
}