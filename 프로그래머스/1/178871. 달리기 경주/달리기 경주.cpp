#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

vector<string> solution(vector<string> players, vector<string> callings) {
    unordered_map<string, int> rank;

    for (int i = 0; i < players.size(); i++) {
        rank[players[i]] = i;
    }

    for (const string& call : callings) {
        int cur = rank[call];

        string& front = players[cur - 1];

        rank[call] = cur - 1;
        rank[front] = cur;

        swap(players[cur], players[cur - 1]);
    }

    return players;
}