#include <iostream>
#include <deque>
using namespace std;

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    
    int n, k;
    int idx = 0;
    cin >> n >> k;
    int arr[n];
    for(int i = 0; i < n; i++){
        arr[i] = 0;
    }

    cout << '<';

    for (int i = 0; i < n; i++) {
        int count = k - 1;
        while(1){
            if (count == 0){
                if (arr[idx] == 0){
                    break;
                }
                else {
                    idx++;
                }
            }
            else{
                if (arr[idx] == 0){
                    idx++;
                    count--;
                }
                else{
                    idx++;
                }
            }

            if (idx == n){
                idx = 0;
            }
        }

        arr[idx] = 1;
        cout << idx + 1;
        idx++;
        if (idx == n){
            idx = 0;
        }
        if(i != (n - 1)){
            cout << ", ";
        }
    }

    cout << '>';

    return 0;
}