#include <iostream>

using namespace std;

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    
    int m;
    int arr[20] = {0, };
    cin >> m;
    
    for(int i = 0; i < m; i++){
        string order;
        cin >> order;
        if (order == "add"){
            int num;
            cin >> num;
            arr[num - 1] = 1;
        }
        else if (order == "remove"){
            int num;
            cin >> num;
            arr[num - 1] = 0;
        }
        else if (order == "check"){
            int num;
            cin >> num;
            if (arr[num - 1] == 1){
                cout << 1 << "\n";
            }
            else{
                cout << 0 << "\n";
            }
        }
        else if (order == "toggle"){
            int num;
            cin >> num;
            if (arr[num - 1] == 1){
                arr[num - 1] = 0;
            }
            else{
                arr[num - 1] = 1;
            }
        }
        else if (order == "all"){
            for (int j = 0; j < 20; j++){
                arr[j] = 1;
            }
        }
        else if (order == "empty"){
            for (int j = 0; j < 20; j++){
                arr[j] = 0;
            }
        }
    }

    return 0;
}