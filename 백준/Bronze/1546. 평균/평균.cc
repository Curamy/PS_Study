#include <iostream>
using namespace std;

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    
    int n;
    cin >> n;

    float arr[n];

    for (int i = 0; i < n; i++){
        cin >> arr[i];
    }

    float max = 0;
    for (int i = 0; i < n; i++){
        if (arr[i] > max){
            max = arr[i];
        }
    }

    float sum = 0;
    for (int i = 0; i < n; i++){
        arr[i] = arr[i] * 100 / max;
        sum += arr[i];
    }

    cout << fixed;
	cout.precision(2);
    cout << sum / n << "\n";
    
    return 0;
}