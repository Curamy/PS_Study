// 빠른 풀이 (열, 우측상단 대각선, 우측하단 대각선 확인을 쉽게 하는 3가지의 배열)
// (x, y)에서 y가 같으면 같은 열,
// x + y가 같으면 우측 상단 대각선,
// x - y가 같으면 우측 하단 대각선 임을 이용

#include <iostream>
#include <cstring>
using namespace std;

int n;
int ans;
bool issued1[15];    // 열 확인용
bool issued2[30];    // x + y 우측 상단 대각선 확인용
bool issued3[30];    // x - y 우측 하단 대각선 확인용

void backtracking(int depth){
    if (depth == n){
        ans++;
        return;
    }

    for (int i = 0; i < n; i++){
        if (issued1[i] || issued2[i + depth] || issued3[depth - i + n - 1]){
            continue;
        }

        issued1[i] = true;
        issued2[i + depth] = true;
        issued3[depth - i + n - 1] = true;

        backtracking(depth + 1);

        issued1[i] = false;
        issued2[i + depth] = false;
        issued3[depth - i + n - 1] = false;
    }
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n;
    ans = 0;
    memset(issued1, 0, sizeof(issued1));
    memset(issued2, 0, sizeof(issued2));
    memset(issued3, 0, sizeof(issued3));
    backtracking(0);

    cout << ans;

    return 0;
}

// 오래 걸리는 방법 (15 * 15 배열을 이용한 기존 풀이)
// #include <iostream>
// #include <cstring>
// using namespace std;

// int n;
// bool board[15][15];
// int ans;

// bool checkBoard(int row, int col){
//     int left = col;
//     int right = col;

//     for (int i = row - 1; i >= 0; i--){
//         if (board[i][col]){
//             return false;
//         }

//         if (left > 0){
//             left--;
//             if (board[i][left]){
//                 return false;
//             }
//         }

//         if (right < n - 1){
//             right++;
//             if (board[i][right]){
//                 return false;
//             }
//         }
//     }

//     return true;
// }

// void backtracking(int depth){
//     if (depth == n){
//         ans++;
//         return;
//     }

//     for (int i = 0; i < n; i++){
//         if (!checkBoard(depth, i)){
//             continue;
//         }

//         board[depth][i] = true;
//         backtracking(depth + 1);
//         board[depth][i] = false;
//     }
// }

// int main() {
//     cin.tie(NULL);
//     cout.tie(NULL);
//     ios_base::sync_with_stdio(false);

//     cin >> n;
//     ans = 0;
//     memset(board, 0, sizeof(board));
//     backtracking(0);

//     cout << ans;

//     return 0;
// }