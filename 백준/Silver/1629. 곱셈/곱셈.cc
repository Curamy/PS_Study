// 분할 거듭제곱 (10^11)%2 = (10^5)*(10^6)%2

#include <iostream>
using namespace std;

long long a, c;
long long func(int b){
    if (b == 0){
        return 1;
    }
    if (b == 1){
        return a % c;
    }

    if (b % 2 == 0){
        return func(b / 2) * func(b / 2) % c;
    }
    else {
        return func(b / 2) * func((b / 2) + 1) % c;
    }
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    
    int b;
    cin >> a >> b >> c;
    
    cout << func(b);

    return 0;
}