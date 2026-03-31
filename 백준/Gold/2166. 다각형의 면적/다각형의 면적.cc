// 다각형의 면적 -> 신발끈 공식?
// 1/2 * | (x1y2 + x2y3 + x3y1) - (x2y1 + x3y2 + x1y3) |

#include <iostream>
#include <algorithm>
using namespace std;

int n;
double point[10001][2];

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n;
    for (int i = 0; i < n; i++){
        double x, y;
        cin >> x >> y;
        point[i][0] = x;
        point[i][1] = y;

        if (i == 0) {
            point[n][0] = x;
            point[n][1] = y;
        }
    }

    double sum1 = 0;
    double sum2 = 0;

    for (int i = 0; i < n; i++){
        sum1 += point[i][0] * point[i + 1][1];
        sum2 += point[i][1] * point[i + 1][0];
    }

    double ans = abs(sum1 - sum2) * 0.5;

    cout << fixed;
    cout.precision(1);
    cout << ans;

    return 0;
}