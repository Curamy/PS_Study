#include <iostream>
#include <math.h>
using namespace std;

bool isPrime(int num){
    if (num <= 1){
        return false;
    }

    for (int i = 2; i <= sqrt(num); i++){
        if (num % i == 0) {
            return false;
        }
    }

    return true;
}

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    
    int n;
    int count = 0;
    cin >> n;
    for(int i = 0; i < n; i++){
        int num;
        cin >> num;

        if(isPrime(num)) {
            count++;
        }
    }
    cout << count << "\n";
    return 0;
}