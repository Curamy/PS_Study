#include <iostream>
#include <map>
#define MOD 1000000007
using namespace std;

long long n;
map<long long, long long> f;

long long fibo (long long num){
    if (f.find(num) != f.end()){
        return f[num];
    }

    if (num % 2 == 0) {
		long long m = num / 2;
		f[num] = ((fibo(m) * fibo(m + 1)) % MOD + (fibo(m - 1) * fibo(m)) % MOD) % MOD;

		return f[num];
	}

    long long m = (num - 1) / 2;
    f[num] = ((fibo(m + 1) * fibo(m + 1)) % MOD + (fibo(m) * fibo(m)) % MOD) % MOD;

    return f[num];
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    
    cin >> n;

    f[0] = 0;
    f[1] = 1;
    f[2] = 1;

    cout << fibo(n) % MOD;

    return 0;
}