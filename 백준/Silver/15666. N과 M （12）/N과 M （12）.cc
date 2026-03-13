#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;
vector<int> arr;
int ans[9];

void func(int depth){
    if (depth == m){
        for (int i = 0; i < m; i++){
            cout << ans[i] << " ";
        }
        cout << "\n";
        return;
    }

    for (int i = 0; i < arr.size(); i++){
        if (depth != 0 && arr[i] < ans[depth - 1]){
            continue;
        }

        ans[depth] = arr[i];
        func(depth + 1);
    }
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n >> m;
    for (int i = 0; i < n; i++){
        int num;
        cin >> num;
        arr.push_back(num);
    }
    sort(arr.begin(), arr.end());
    arr.erase(unique(arr.begin(), arr.end()), arr.end());

    fill(ans, ans + 9, 0);
    func(0);
    
    return 0;
}