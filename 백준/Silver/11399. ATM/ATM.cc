#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++){
        cin >> arr[i];
    }
    sort(arr, arr + n);

    int sum = 0;
    for(int j = 0; j < n; j++){
        sum += arr[j] * (n - j);
    }

    cout << sum;

    return 0;
}