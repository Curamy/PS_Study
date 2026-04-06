#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
int stat[21][21];
int plus_stat[21][21];
vector<int> team1;
vector<int> team2;
int ans;

void countGap(int d){
    if (d == n / 2){
        for (int i = 2; i <= n; i++){
            if (find(team1.begin(), team1.end(), i) == team1.end()){
                team2.push_back(i);
            }
        }

        int team1Sum = 0;
        int team2Sum = 0;

        for (int i = 0; i < team1.size(); i++){
            for (int j = i + 1; j < team1.size(); j++){
                team1Sum += plus_stat[team1[i]][team1[j]];
            }
        }

        for (int i = 0; i < team2.size(); i++){
            for (int j = i + 1; j < team2.size(); j++){
                team2Sum += plus_stat[team2[i]][team2[j]];
            }
        }

        if (abs(team1Sum - team2Sum) < ans){
            ans = abs(team1Sum - team2Sum);
        }

        team2.clear();
        return;
    }

    for (int i = team1[d - 1] + 1; i <= n; i++){
        team1.push_back(i);
        countGap(d + 1);
        team1.pop_back();
    }
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    
    ans = 999999999;
    cin >> n;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            cin >> stat[i][j];
        }
    }

    for (int i = 1; i < n; i++){
        for (int j = i + 1; j <= n; j++){
            plus_stat[i][j] = stat[i][j] + stat[j][i];
        }
    }

    team1.push_back(1);
    countGap(1);

    cout << ans;

    return 0;
}