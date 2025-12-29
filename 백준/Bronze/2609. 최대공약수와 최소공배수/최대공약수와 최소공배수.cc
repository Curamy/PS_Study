#include <iostream>
using namespace std;

int gcd(int a, int b) {
    if(b == 0){
        return a;
    }
    else {
        return gcd(b, a % b);
    }
}

int lcm(int a, int b) {
    return (a * b) / gcd(a, b);
}

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    
    int a, b;
    cin >> a >> b;

    cout << gcd(a, b) << "\n";
    cout << lcm(a, b) << "\n";
    return 0;
}