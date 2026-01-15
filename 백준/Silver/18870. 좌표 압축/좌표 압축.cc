#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 벡터 하나 카피한 뒤 unique, erase, lower_bound 사용

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    vector<int> v;
    vector<int> cv;

    for (int i = 0; i < n; i++){
        int num;
        cin >> num;
        v.push_back(num);
        cv.push_back(num);
    }

    sort(cv.begin(), cv.end());
    cv.erase(unique(cv.begin(), cv.end()), cv.end());

    for (int i = 0; i < n; i++){
        cout << lower_bound(cv.begin(), cv.end(), v[i]) - cv.begin() << " ";
    }

    return 0;
}