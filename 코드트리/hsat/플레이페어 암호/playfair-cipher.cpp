#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string message;
string key;

int board[5][5];
bool is_exist[26];

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> message >> key;

    fill(board[0], board[5], 0);
    fill(is_exist, is_exist + 26, 0);
    is_exist[9] = true;

    int row = 0;
    int col = 0;

    for (char c : key){
        int num = c - 65;
        
        if (!is_exist[num]){
            is_exist[num] = true;
            board[row][col++] = num;

            if (col == 5){
                row++;
                col = 0;
            }
        }
    }

    for (int i = 0; i < 26; i++){
        if (!is_exist[i]){
            is_exist[i] = true;
            board[row][col++] = i;
        }

        if (col == 5){
            row++;
            col = 0;
        }
    }

    for (int i = 0; i < message.length(); i++){
        int c1, c2;
        c1 = message[i] - 65;
        if (i + 1 == message.length()){
            c2 = 23;
        }
        else {
            c2 = message[i + 1] - 65;
            if (c1 == c2){
                if (c1 == 23){
                    c2 = 16;
                }
                else {
                    c2 = 23;
                }
            }
            else {
                i++;
            }
        }

        int row1, col1, row2, col2;
        for (int r = 0; r < 5; r++){
            for (int c = 0; c < 5; c++){
                if (board[r][c] == c1){
                    row1 = r;
                    col1 = c;
                }
                if (board[r][c] == c2){
                    row2 = r;
                    col2 = c;
                }
            }
        }

        if (row1 == row2){
            c1 = board[row1][(col1 + 1) % 5];
            c2 = board[row2][(col2 + 1) % 5];
        }
        else if (col1 == col2){
            c1 = board[(row1 + 1) % 5][col1];
            c2 = board[(row2 + 1) % 5][col2];
        }
        else {
            c1 = board[row1][col2];
            c2 = board[row2][col1];
        }
        cout << char(c1 + 65) << char(c2 + 65);
    }

    return 0;
}
