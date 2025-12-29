#include <iostream>
using namespace std;

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int sum = 0;
    for (int i = 0; i < 5; i++){
        int num;
        cin >> num;
        sum += num * num;
    }
    cout << sum % 10 << "\n";
    return 0;
}