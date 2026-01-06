#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    
    int n,m;
    cin >> n >> m;
    set<string> hear;
    set<string> dbj;

    for (int i = 0; i < n; i++){
        string name;
        cin >> name;
        hear.insert(name);
    }
    
    for (int i = 0; i < m; i++){
        string name;
        cin >> name;
        auto it = hear.find(name);
        if (it != hear.end()){
            dbj.insert(name);
        }
    }

    int count = dbj.size();
    cout << count << "\n";
    for(auto iter = dbj.begin(); iter != dbj.end(); iter++){
        cout << *iter << "\n";
    }

    return 0;
}