#include <iostream>
using namespace std;

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n = 30;
    int arr[n] = {0,};
    for(int i = 0; i < 28; i++) {
        int j;
        cin >> j;
        arr[j - 1] = 1;
    }
    for(int i = 0; i < n; i++) {
        if(arr[i] == 0) {
            cout << i + 1 << '\n';
        }
    }
    return 0;
}