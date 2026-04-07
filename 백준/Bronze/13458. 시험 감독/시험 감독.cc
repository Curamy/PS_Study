#include <iostream>
using namespace std;

    int n, b, c;
    int room[1000001];
    long long ans;

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> room[i];
    }
    cin >> b >> c;

    ans = n;

    for (int i = 0; i < n; i++){
        int left = room[i] - b;
        if (left <= 0){
            continue;
        }

        if (left % c == 0){
            ans += left / c;
        }        

        else {
            ans += left / c + 1;
        }
    }

    cout << ans;

    return 0;
}