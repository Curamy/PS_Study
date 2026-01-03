#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    
    int n, m;
    cin >> n;
    vector<int> v;
    for(int i=0; i<n; i++){
        int num;
        cin >> num;
        v.push_back(num);
    }
    sort(v.begin(), v.end());

    cin >> m;
    for(int j=0; j<m; j++){
        int target;
        cin >> target;
        int count = upper_bound(v.begin(), v.end(), target) - lower_bound(v.begin(), v.end(), target);
        cout << count << " ";
    }

    return 0;
}