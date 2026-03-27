#include <string>
#include <vector>

using namespace std;

int solution(vector<string> babbling) {
    int answer = 0;
    for (int i = 0; i < babbling.size(); i++){
        string str = babbling[i];
        bool used[] = {0, 0, 0, 0};
        bool isValid = true;
        
        int idx = 0;
        while(idx < str.length()){
            if (str[idx] == 'a' && used[0] == false){
                if (str[idx + 1] == 'y' && str[idx + 2] == 'a'){
                    used[0] = true;
                    idx += 3;
                }
                else {
                    isValid = false;
                    break;
                }
            }
            
            else if (str[idx] == 'y' && used[1] == false){
                if (str[idx + 1] == 'e'){
                    used[1] = true;
                    idx += 2;
                }
                else {
                    isValid = false;
                    break;
                }
            }
            
            else if (str[idx] == 'w' && used[2] == false){
                if (str[idx + 1] == 'o' && str[idx + 2] == 'o'){
                    used[2] = true;
                    idx += 3;
                }
                else {
                    isValid = false;
                    break;
                }
            }
            
            else if (str[idx] == 'm' && used[3] == false){
                if (str[idx + 1] == 'a'){
                    used[3] = true;
                    idx += 2;
                }
                else {
                    isValid = false;
                    break;
                }
            }
            
            else {
                isValid = false;
                break;
            }
        }
        
        if (isValid){
            answer++;
        }
    }
    return answer;
}