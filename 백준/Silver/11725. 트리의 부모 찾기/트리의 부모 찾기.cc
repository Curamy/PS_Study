#include <iostream>
#include <vector>
using namespace std;

struct Node {
    int depth;
    int pa;
};

Node nodes[100001];
vector<int> link[100001];
bool visited[100001];
int n;

void dfs(int node1){
    for (int i = 0; i < link[node1].size(); i++){
        int node2 = link[node1][i];
        if (visited[node2]){
            continue;
        }

        if (nodes[node1].depth < nodes[node2].depth){
            nodes[node2].depth = nodes[node1].depth + 1;
            nodes[node2].pa = node1;
        }
        else{
            nodes[node1].depth = nodes[node2].depth + 1;
            nodes[node1].pa = node2;
        }

        visited[node2] = true;
        dfs(node2);
    }
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    nodes[1].depth = 0;
    nodes[1].pa = 1;

    cin >> n;

    for (int i = 2; i <= n; i++){
        nodes[i].depth = 100001;
        nodes[i].pa = 0;
    }

    for (int i = 1; i < n; i++){
        int num1, num2;
        cin >> num1 >> num2;
        link[num1].push_back(num2);
        link[num2].push_back(num1);
    }

    visited[1] = true;
    dfs(1);

    for (int i = 2; i <= n; i++){
        cout << nodes[i].pa << "\n";
    }

    return 0;
}