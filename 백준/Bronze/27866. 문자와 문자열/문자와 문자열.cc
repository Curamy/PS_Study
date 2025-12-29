#include <iostream>
using namespace std;

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    
    string s;
    cin >> s;
    int num;
    cin >> num;

    cout << s[num - 1] << '\n';
    return 0;
}