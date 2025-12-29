#include <iostream>
using namespace std;

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n, k;
    cin >> n >> k;
    if (n - k > k){
        k = n - k;
    }

    int result;
    if (k == 0){
        result = 1;
    }
    else {
        int iter = k;
        int top = 1;
        int bot = 1;
        for (int i = 0; i < iter; i++){
            top *= n;
            n--;
        }
        for (int j = 0; j < iter; j++){
            bot *= k;
            k--;
        }
        result = top / bot;
    }

    cout << result << "\n";

    return 0;
}