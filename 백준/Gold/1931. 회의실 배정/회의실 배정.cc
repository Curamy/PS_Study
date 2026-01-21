#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<pair<int, int>> v;
int n;
int ans;

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n;
    for (int i = 0; i < n; i++){
        int start, end;
        cin >> start >> end;
        v.push_back(make_pair(start, end));
    }

    sort(v.begin(), v.end());

    for (int i = 0; i < n; i++){
        bool choice = true;
        bool final = true;
        int st_base = v[i].first;
        int et_base = v[i].second;
        for (int j = i + 1; j < n; j++){
            int st = v[j].first;
            int et = v[j].second;
            if (et < et_base){
                choice = false;
                final = false;
                i = j - 1;
                break;
            }
            if (st >= et_base){
                final = false;
                i = j - 1;
                break;
            }
        }
        if (choice == true){
            ans++;
        }
        if (final == true){
            break;
        }
    }

    cout << ans;

    return 0;
}