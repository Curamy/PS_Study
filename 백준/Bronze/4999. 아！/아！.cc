#include <iostream>
using namespace std;

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    string j, d;

    cin >> j;
    cin >> d;
    if (j.length() < d.length()){
        cout << "no" << "\n";
    }
    else{
        cout << "go" << "\n";
    }

    return 0;
}