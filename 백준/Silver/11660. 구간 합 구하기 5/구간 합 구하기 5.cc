#include <iostream>
#include <cstring>
using namespace std;

int n, m;
int board[1025][1025];
int rsum[1025][1025];
int csum[1025][1025];
int asum[1025][1025];

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    memset(board, 0, sizeof(board));
    memset(rsum, 0, sizeof(rsum));
    memset(csum, 0, sizeof(csum));
    memset(asum, 0, sizeof(asum));

    cin >> n >> m;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            cin >> board[i][j];

            rsum[i][j] = rsum[i][j - 1] + board[i][j];
            csum[i][j] = csum[i - 1][j] + board[i][j];
            asum[i][j] = asum[i - 1][j - 1] + rsum[i][j] + csum[i][j] - board[i][j];
        }
    }

    for (int i = 0; i < m; i++){
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        cout << asum[x2][y2] - asum[x2][y1 - 1] - asum[x1 - 1][y2] + asum[x1 - 1][y1 - 1] << "\n";
    }

    return 0;
}