#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<string> wallpaper) {
    int top = 51;
    int bot = -1;
    int left = 51;
    int right = -1;
    
    for (int i = 0; i < wallpaper.size(); i++){
        string str = wallpaper[i];
        for (int j = 0; j < str.length(); j++){
            char ch = str[j];
            if (ch == '#'){
                if (i < top){
                    top = i;
                }
                if (i + 1 > bot){
                    bot = i + 1;
                }
                if (j < left){
                    left = j;
                }
                if (j + 1 > right){
                    right = j + 1;
                }
            }
        }
    }
    
    vector<int> answer;
    answer.push_back(top);
    answer.push_back(left);
    answer.push_back(bot);
    answer.push_back(right);
    return answer;
}