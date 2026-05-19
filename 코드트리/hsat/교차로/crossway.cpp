#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int N;
vector<long long> t;
vector<string> w;
queue<pair<int, int>> qa;
queue<pair<int, int>> qb;
queue<pair<int, int>> qc;
queue<pair<int, int>> qd;

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> N;

    t.resize(N);
    w.resize(N);

    int answer[N];
    fill(answer, answer + N, -1);


    for (int i = 0; i < N; i++) {
        cin >> t[i] >> w[i];
    }

    for (int i = 0; i < N; i++) {
        if (w[i] == "A") {
            qa.push({t[i], i});
        }
        else if (w[i] == "B") {
            qb.push({t[i], i});
        }
        else if (w[i] == "C") {
            qc.push({t[i], i});
        }
        else {
            qd.push({t[i], i});
        }
    }

    int curT = 0;
    while(true){
        if (qa.empty() && qb.empty() && qc.empty() && qd.empty()){
            break;
        }

        if (!qa.empty() && qa.front().first <= curT &&
            !qb.empty() && qb.front().first <= curT &&
            !qc.empty() && qc.front().first <= curT &&
            !qd.empty() && qd.front().first <= curT) {
            break;
        }
        
        bool a_go = false;
        bool b_go = false;
        bool c_go = false;
        bool d_go = false;

        // a부터 체크
        if (!qa.empty() && (qa.front().first <= curT) && (qd.empty() || (qd.front().first > curT))){
            a_go = true;
        }
        if (!qb.empty() && (qb.front().first <= curT) && (qa.empty() || (qa.front().first > curT))){
            b_go = true;
        }
        if (!qc.empty() && (qc.front().first <= curT) && (qb.empty() || (qb.front().first > curT))){
            c_go = true;
        }
        if (!qd.empty() && (qd.front().first <= curT) && (qc.empty() || (qc.front().first > curT))){
            d_go = true;
        }

        // a부터 진행
        if (a_go){
            int time = curT;
            int num = qa.front().second;
            qa.pop();
            answer[num] = time;
        }
        if (b_go){
            int time = curT;
            int num = qb.front().second;
            qb.pop();
            answer[num] = time;
        }
        if (c_go){
            int time = curT;
            int num = qc.front().second;
            qc.pop();
            answer[num] = time;
        }
        if (d_go){
            int time = curT;
            int num = qd.front().second;
            qd.pop();
            answer[num] = time;
        }

        if (!a_go && !b_go && !c_go && !d_go) {
            int next = 1000000001;
            if (!qa.empty()) next = min(next, qa.front().first);
            if (!qb.empty()) next = min(next, qb.front().first);
            if (!qc.empty()) next = min(next, qc.front().first);
            if (!qd.empty()) next = min(next, qd.front().first);
            
            if (next == 1000000001) break;
            curT = next;
        } else {
            curT++;
        }
    }

    for (int i = 0; i < N; i++){
        cout << answer[i] << "\n";
    }
    return 0;
}
