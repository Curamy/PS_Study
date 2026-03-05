#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;
vector<int> nums;

bool visited[8];
int ans[8];

void dfs(int depth){
    if (depth == m){
        for (int i = 0; i < m; i++){
            cout << ans[i] << " ";
        }
        cout << "\n";
        return;
    }

    int last = 0;
    for (int j = 0; j < n; j++){
        if (visited[j] || nums[j] == last){
            continue;
        }

        visited[j] = true;
        ans[depth] = nums[j];
        last = nums[j];
        dfs(depth + 1);
        visited[j] = false;
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
        nums.push_back(num);
    }
    sort(nums.begin(), nums.end());

    dfs(0);

    return 0;
}