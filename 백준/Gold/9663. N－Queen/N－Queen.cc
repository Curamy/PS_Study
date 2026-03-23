#include <iostream>
#include <cstring>
using namespace std;

int n;
bool board[15][15];
int ans;

bool checkBoard(int row, int col){
    int left = col;
    int right = col;

    for (int i = row - 1; i >= 0; i--){
        if (board[i][col]){
            return false;
        }

        if (left > 0){
            left--;
            if (board[i][left]){
                return false;
            }
        }

        if (right < n - 1){
            right++;
            if (board[i][right]){
                return false;
            }
        }
    }

    return true;
}

void backtracking(int depth){
    if (depth == n){
        ans++;
        return;
    }

    for (int i = 0; i < n; i++){
        if (!checkBoard(depth, i)){
            continue;
        }

        board[depth][i] = true;
        backtracking(depth + 1);
        board[depth][i] = false;
    }
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n;
    ans = 0;
    memset(board, 0, sizeof(board));
    backtracking(0);

    cout << ans;

    return 0;
}