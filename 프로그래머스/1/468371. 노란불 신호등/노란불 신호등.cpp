#include <string>
#include <vector>

using namespace std;

int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int lcm(int a, int b) {
    return (a * b) / gcd(a, b);
}

bool checkYellow(int time, int g, int y, int r){
    int cycle = g + y + r;
    if (time % cycle > g && time % cycle < (g + y + 1)){
        return true;
    }
    else {
        return false;
    }
}

int solution(vector<vector<int>> signals) {
    int period = 1;
    for (int i = 0; i < signals.size(); i++){
        period = lcm(period, (signals[i][0] + signals[i][1] + signals[i][2]));
    }
    
    for (int i = 1; i <= period; i++){
        bool okay = true;
        
        for (int j = 0; j < signals.size(); j++){
            if (!checkYellow(i, signals[j][0], signals[j][1], signals[j][2])){
                okay = false;
                break;
            }
        }
        
        if (okay){
            return i;
        }
    }

    return -1;
}
