#include <iostream>
#include <cmath>
using namespace std;

int n, row, col;
int cnt;
int ans;

void check(int r, int c, int l){
    if (l == 1){
        ans = cnt + 2 * (row - r) + (col - c);
    }

    else{
        int idx = (pow(2, l) / 2) * (pow(2, l) / 2);
        l--;
        int len = pow(2, l);
        
        // 1사분면
        if (row < r + len && col < c + len) {
            check(r, c, l);
        }

        // 2사분면
        else if (row < r + len && col >= c + len){
            cnt += idx;
            check(r, c + len, l);
        }

        // 3사분면
        else if (row >= r + len && col < c + len){
            cnt += 2 * idx;
            check(r + len, c, l);
        }
        
        // 4사분면
        else{
            cnt += 3 * idx;
            check(r + len, c + len, l);
        }
    }
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n >> row >> col;

    check(0, 0, n);
    cout << ans;

    return 0;
}