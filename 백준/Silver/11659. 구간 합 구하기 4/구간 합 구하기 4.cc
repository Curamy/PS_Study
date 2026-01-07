#include <iostream>
using namespace std;

// 누적 합으로 풀기

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;
    int sum[n + 1];
    sum[0] = 0;
    for (int i = 1; i <= n; i++){
        int num;
        cin >> num;
        sum[i] = sum[i - 1] + num;
    }

    for (int j = 0; j < m; j++){
        int a, b;
        cin >> a >> b;
        int result = sum[b] - sum[a - 1];
        cout << result << "\n";
    }

    return 0;
}