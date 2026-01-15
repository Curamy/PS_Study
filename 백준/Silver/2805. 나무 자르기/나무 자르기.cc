#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 이진 탐색

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;

    vector<int> trees;

    for (int i = 0; i < n; i++){
        int num;
        cin >> num;
        trees.push_back(num);
    }

    sort(trees.begin(), trees.end());

    int start = 0;
    int end = trees[n-1];
    int answer;

    while (start <= end){
        long long sum = 0;
        int mid = (start + end) / 2;
        for (int i = 0; i < n; i++){
            if (trees[i] > mid){
                sum += (trees[i] - mid);
            }
        }
        if (sum < m){
            end = mid - 1;
        }
        else {
            answer = mid;
            start = mid + 1;
        }
    }

    cout << answer;

    return 0;
}