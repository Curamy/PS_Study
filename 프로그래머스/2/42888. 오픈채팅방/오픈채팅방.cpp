#include <string>
#include <vector>
#include <map>
#include <sstream>
#include <iostream>

using namespace std;

vector<string> solution(vector<string> record) {
    map<string, string> names;
    vector<pair<string, string>> list;
    

    for(string str : record) {
        stringstream ss(str);
        string action, id, name;
        ss >> action >> id >> name;
        
        if (action == "Enter" || action == "Change"){
            names[id] = name;   
        }
        if (action == "Enter" || action == "Leave"){
            list.push_back({id, action});   
        }
    }
        
    vector<string> answer;
    
    for (auto x : list){
        if (x.second == "Enter"){
            answer.push_back(names[x.first] + "님이 들어왔습니다.");
        }
        else if (x.second == "Leave"){
            answer.push_back(names[x.first] + "님이 나갔습니다.");
        }
    }
    
    return answer;
}