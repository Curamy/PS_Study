#include <string>
#include <vector>
#include <set>
#include <iostream>

using namespace std;
set<string> words;
set<string> spo_words;

int solution(string message, vector<vector<int>> spoiler_ranges) {
    int answer = 0;
    
    int start = 0;
    int end = 0;
    int spoiler_idx = 0;
    
    for (int i = 0; i <= message.length(); i++){
        if (message[i] == ' ' || i == message.length()){
            end = i - 1;
            string word = message.substr(start, end - start + 1);
            bool spoiled = false;
            
            for (int j = spoiler_idx; j < spoiler_ranges.size(); j++){
                if (end < spoiler_ranges[j][0] || start > spoiler_ranges[j][1]){
                    continue;
                }
                else {
                    spoiled = true;
                    spoiler_idx = j;
                    break;
                }
            }
        
            if(!spoiled){
                words.insert(word);
            }
            else{
                spo_words.insert(word);
            }
            
            start = i + 1;
        }    
    }
    
    for (auto it : spo_words){
        if (words.find(it) == words.end()){
            answer++;
        }
    }
    
    return answer;
}