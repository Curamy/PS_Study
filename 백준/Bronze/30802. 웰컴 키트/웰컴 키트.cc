#include <iostream>
using namespace std;

int set(int num, int t){
    if (num % t == 0){
        return (num / t);
    }
    else {
        return (num / t) + 1;
    }
}

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    
    int n;
    int s, m, l, xl, xxl, xxxl;
    int t, p;
    cin >> n;
    cin >> s >> m >> l >> xl >> xxl >> xxxl;
    cin >> t >> p;

    int sum = set(s, t) + set(m, t) + set(l, t) + set(xl, t) + set(xxl, t) + set(xxxl, t);
    cout << sum << "\n";
    cout << n / p << " " << n % p << "\n";
    
    return 0;
}