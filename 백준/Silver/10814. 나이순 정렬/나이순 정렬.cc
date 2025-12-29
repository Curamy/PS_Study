#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool compare (pair<int, string> a, pair<int, string> b){
    return a.first < b.first;
}

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    
    int n;
    cin >> n;

    vector<pair<int, string>> mem(n);

    for (int i = 0; i < n; i++){
        cin >> mem[i].first >> mem[i].second;
    }

    stable_sort(mem.begin(), mem.end(), compare);

    for (int i = 0; i < n; i++){
        cout << mem[i].first << " " << mem[i].second << "\n";
    }
    
    return 0;
}