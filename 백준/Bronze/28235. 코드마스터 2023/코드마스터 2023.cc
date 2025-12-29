#include <iostream>
using namespace std;

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    
    string s;
    cin >> s;
    if (s == "SONGDO") {
        cout << "HIGHSCHOOL\n";
    } else if (s == "CODE") {
        cout << "MASTER\n";
    } else if (s == "2023") {
        cout << "0611\n";
    } else if (s == "ALGORITHM") {
        cout << "CONTEST\n";
    }
    return 0;
}