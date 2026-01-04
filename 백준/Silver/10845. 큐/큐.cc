#include <iostream>
#include <deque>
using namespace std;

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    
    deque<int> v;
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
        else if (order == "front"){
            if (v.empty()){
                cout << "-1\n";
            } else {
                cout << v.front() << "\n";
            }
        }
        else if (order == "back"){
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
                cout << v.front() << "\n";
                v.pop_front();
            }
        }
    }

    return 0;
}