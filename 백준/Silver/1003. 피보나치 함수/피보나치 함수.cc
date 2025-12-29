#include <iostream>
#include <cstdio>

int main(){
    int test_case;
    int zero[41];
    int one[41];
    zero[0] = 1;
    zero[1] = 0;
    one[0] = 0;
    one[1] = 1;
    for (int i = 2; i<41; i++){
        zero[i] = zero[i-1] + zero[i-2];
        one[i] = one[i-1] + one[i-2];
    }

    scanf("%d", &test_case);
    for (int tc = 0; tc < test_case; tc++)
    {
        int n, ans0, ans1;
        scanf("%d", &n);
        // n에 대한 답을 구한다.
        // ans0 = 답 구하기;
        printf("%d %d\n", zero[n], one[n]);
    }
    return 0;
}
