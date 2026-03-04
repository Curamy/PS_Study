#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;
vector<int> nums;

bool visited[8];
int ans[8];
int pos;

void dfs(int idx, int left){
    if (left == 1){
        for (int i = 0; i < m; i++){
            cout << ans[i] << " ";
        }
        cout << "\n";
        visited[idx] = false;
        return;
    }

    for (int j = 0; j < n; j++){
        if (visited[j]){
            continue;
        }

        visited[j] = true;
        ans[pos++] = nums[j];
        dfs(j, left - 1);
        visited[j] = false;
        pos--;
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
    pos = 0;

    for (int i = 0; i < n; i++){
        visited[i] = true;
        ans[pos++] = nums[i];
        dfs(i, m);
        visited[i] = false;
        pos--;
    }

    return 0;
}