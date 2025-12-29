#include <iostream>
using namespace std;

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    
    while (1){
        int num;
        cin >> num;
        if (num == 0){
            break;
        }

        string str = to_string(num);
        int i = 0;
        int j = str.length() - 1;
        bool palindrome = false; 

        while(1){
            if (i >= j){
                palindrome = true;
                break;
            }

            if (str[i] == str[j]){
                i++;
                j--;
            }
            else {
                break;
            }
        }

        if (palindrome == true){
            cout << "yes\n";
        }
        else {
            cout << "no\n";
        }
    }
    
    return 0;
}