#include <iostream>
using namespace std;

int main() {
    int a, b;
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    while (!(cin >> a >> b).eof()){
        cout << a + b << "\n";
    }
    return 0;
}