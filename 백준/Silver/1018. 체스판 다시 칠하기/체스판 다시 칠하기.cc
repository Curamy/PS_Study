#include <iostream>
using namespace std;

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    
    int n, m;
    cin >> n >> m;
    int arr[n][m];
    
    int arr1[8][8];     // 0 시작
    int arr2[8][8];     // 1 시작
    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){
            arr1[i][j] = (i + j) % 2;
        }
    }
    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){
            arr2[i][j] = (i + j + 1) % 2;
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            char c;
            cin >> c;
            if (c == 'W'){
                arr[i][j] = 0;
            }
            else {
                arr[i][j] = 1;
            }
        }
    }
    
    // for(int i = 0; i < n; i++){
    //     for(int j = 0; j < m; j++){
    //         cout << arr[i][j];
    //     }
    //     cout << "\n";
    // }
    
    int count0, count1;
    int min = 999999;
    int cmp = 0;

    for (int i = 0; i <= n - 8; i++){
        for (int j = 0; j <= m - 8; j++){
            count0 = 0;
            count1 = 0;

            for (int x = i; x < i + 8; x++){
                for (int y = j; y < j + 8; y++){
                    if (arr[x][y] != arr1[x - i][y - j]){
                        count0++;
                    }
                    if (arr[x][y] != arr2[x - i][y - j]){
                        count1++;
                    }
                }
            }

            if (count0 < min){
                min = count0;
            }
            if (count1 < min){
                min = count1;
            }
        }
    }

    cout << min;
    

    return 0;
}