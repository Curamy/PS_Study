#include <iostream>
using namespace std;

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    
    string s;
    cin >> s;
    for(int i=0; i<s.length(); i++) {
        if(s[i] >= 'a' && s[i] <= 'z') {
            s[i] -= 32;
        } else if(s[i] >= 'A' && s[i] <= 'Z') {
            s[i] += 32;
        }
    }
    cout << s << "\n";
    return 0;
}