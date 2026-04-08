#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Hospital{
    int y, x;
    vector<int> dist_to_people;
};

struct People{
    int y, x;
};

int n, m;
vector<Hospital> hospital;
vector<People> people;
int hosp_cnt;
int peo_cnt;
int picked_hospital[13];
int ans;

void backtracking(int count){
    if (count == m){
        int min_dist[peo_cnt];
        fill(min_dist, min_dist + peo_cnt, 99999);
        int sum = 0;
        
        for (int i = 0; i < m; i++){
            int hosp = picked_hospital[i];
            for (int j = 0; j < peo_cnt; j++){
                if (min_dist[j] > hospital[hosp].dist_to_people[j]){
                    min_dist[j] = hospital[hosp].dist_to_people[j];
                }
            }
        }

        for (auto d : min_dist){
            sum += d;
        }
        
        if (sum < ans){
            ans = sum;
        }
        return;
    }

    for (int next_hos = picked_hospital[count - 1] + 1; next_hos < hosp_cnt; next_hos++){
        picked_hospital[count] = next_hos;
        backtracking(count + 1);
    }
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    ans = 99999;
    cin >> n >> m;

    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            int type;
            cin >> type;

            if (type == 1){
                people.push_back({i, j});
            }
            
            if (type == 2){
                hospital.push_back({i, j});
            }
        }
    }

    hosp_cnt = hospital.size();
    peo_cnt = people.size();

    for (int i = 0; i < hosp_cnt; i++){
        for (int j = 0; j < peo_cnt; j++){
            int d = abs(hospital[i].y - people[j].y) + abs(hospital[i].x - people[j].x);
            hospital[i].dist_to_people.push_back(d);
        }
    }

    for (int i = 0; i <= hosp_cnt - m; i++){
        picked_hospital[0] = i;
        backtracking(1);
    }

    cout << ans;

    return 0;
}