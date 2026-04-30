#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(int n, int w, int num) {
    int box_cnt[w];
    int q = n / w;
    int r = n % w;
    if (q % 2 == 0) {
        for (int i = 0; i < w; i++){
            box_cnt[i] = q;
            if (r > 0){
                box_cnt[i]++;
                r--;
            }
        }
    }
    else {
        for (int i = w - 1; i >= 0; i--){
            box_cnt[i] = q;
            if (r > 0){
                box_cnt[i]++;
                r--;
            }
        }
    }
    
    int row, col;
    row = num / w;
    if (row % 2 == 0){
        col = 0;
        if (num % w != 0){
            row++;
            col += ((num % w) - 1);
        }
    }
    else {
        col = w - 1;
        if (num % w != 0){
            row++;
            col -= ((num % w) - 1);
        }
    }
    
    int answer = box_cnt[col] - row + 1;
    return answer;
}