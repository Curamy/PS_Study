#include <iostream>
#include <vector>
using namespace std;

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    
    vector<int> v;
    int n;
    cin >> n;
    
    for(int i = 0; i < n; i++){
        string order;
        cin >> order;
        if (order == "size"){
            cout << v.size() << "\n";
        }
        else if (order == "empty"){
            if (v.empty()) {
                cout << "1\n";
            } else {
                cout << "0\n";
            }
        }
        else if (order == "top"){
            if (v.empty()){
                cout << "-1\n";
            } else {
                cout << v.back() << "\n";
            }
        }
        else if (order == "push"){
            int num;
            cin >> num;
            v.emplace_back(num);
        }
        else if (order == "pop"){
            if (v.empty()){
                cout << "-1\n";
            } else {
                cout << v.back() << "\n";
                v.pop_back();
            }
        }
    }

    return 0;
}