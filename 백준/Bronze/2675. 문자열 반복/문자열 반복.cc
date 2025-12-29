#include <iostream>
using namespace std;

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    
    int t;
    cin >> t;
    int r;
    string s;

    for(int i = 0; i < t; i++){
        cin >> r >> s;
        int len = s.length();
        for (int j = 0; j < s.length(); j++){
            for (int k = 0; k < r; k++){
                cout << s[j];
            }
        }

        cout << "\n";
    }
    return 0;
}