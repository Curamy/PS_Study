#include <iostream>
using namespace std;

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    
    int m, f;
    while (1) {
        cin >> m >> f;
        if (m == 0 && f == 0) break;
        cout << m + f << '\n';
    }
    return 0;
}