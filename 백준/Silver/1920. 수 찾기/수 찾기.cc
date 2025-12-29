#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n, m;
vector<int> v;

int BS(int target){  // Binary Search
    int start = 0;
    int end = v.size() - 1;

    while (start <= end){
        int mid = (start + end) / 2;
        if (target == v[mid]){
            return 1;
        }

        if (target < v[mid]){
            end = mid - 1;
        }
        else {
            start = mid + 1;
        }
    }

    return 0;
}

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n;
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
        cout << BS(target) << "\n";
    }

    return 0;
}