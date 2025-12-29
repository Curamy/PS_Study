#include <iostream>
using namespace std;

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    
    int arr[9];
    int max_num = 0;
    int max_idx = 1;

    for(int i = 0; i < 9; i++){
        cin >> arr[i];
    }

    for(int i = 0; i < 9; i++){
        if (arr[i] > max_num) {
            max_num = arr[i];
            max_idx = i + 1;
        }
    }
    
    cout << max_num << "\n";
    cout << max_idx << "\n";
    return 0;
}