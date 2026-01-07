#include <iostream>
using namespace std;

// 피보나치. f(n) = f(n - 1) + f(n - 2). 가장 마지막 자리를 세로로 채울 경우 f(n - 1), 가로로 채울 경우 f(n - 2)와 같음

int fibonacci[1001];

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    fibonacci[0] = 0;
    fibonacci[1] = 1;
    fibonacci[2] = 2;
    for (int i = 3; i <= n; i++){
        fibonacci[i] = (fibonacci[i - 1] + fibonacci[i - 2]) % 10007;
    }
    cout << fibonacci[n];

    return 0;
}