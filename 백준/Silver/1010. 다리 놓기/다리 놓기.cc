#include <iostream>
using namespace std;

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int t;
    int n, m;
    cin >> t;
    for (int i=0; i<t; i++){
        cin >> n >> m;
        if(n > (m - n)){
            n = m - n;
        }

        long long top = m;
        long long bot = n;

        if(n == 0){
            cout << 1 << "\n";
        }
        else if(n == 1){
            cout << m << "\n";
        }
        else{
            for (int j=1; j<n; j++){
                top *= (m - j);
            }
            for (int k=1; k<n; k++){
                bot *= (n - k);
            }
            cout << top / bot << "\n";
        }
    }
}