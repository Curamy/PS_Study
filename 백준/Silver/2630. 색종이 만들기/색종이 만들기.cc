#include <iostream>
using namespace std;

int paper[129][129];
int wcnt;
int bcnt;
int color;

void dfs(int x, int y, int len){
    int clear = 1;

    if (paper[x][y] == 0){
        color = 0;
    }
    else {
        color = 1;
    }

    for (int i = x; i < (x + len); i++){
        for (int j = y; j < (y + len); j++){
            if (paper[i][j] != color){
                clear = 0;
            }
        }
    }

    if (clear == 0){
        dfs(x, y, len / 2);
        dfs(x + (len / 2), y, (len / 2));
        dfs(x, y + (len / 2), (len / 2));
        dfs(x + (len / 2), y + (len / 2), (len / 2));
    }

    else{
        if (color == 0){
            wcnt++;
        }
        else{
            bcnt++;
        }
    }
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cin >> paper[i][j];
        }
    }

    dfs(1, 1, n);

    cout << wcnt << "\n" << bcnt;

    return 0;
}