#include <iostream>
#include <cstring>
using namespace std;

int n;
int tree[27][2];
bool visited[27];

void pre(int i){
    if (visited[i]){
        return;
    }
    visited[i] = true;
    cout << (char)(i + 'A' - 1);

    if (tree[i][0] > 0){
        pre(tree[i][0]);
    }

    if (tree[i][1] > 0){
        pre(tree[i][1]);
    }

    return;
}

void in(int i){
    if (visited[i]){
        return;
    }
    visited[i] = true;

    if (tree[i][0] > 0){
        in(tree[i][0]);
    }

    cout << (char)(i + 'A' - 1);

    if (tree[i][1] > 0){
        in(tree[i][1]);
    }

    return;
}

void post(int i){
    if (visited[i]){
        return;
    }
    visited[i] = true;

    if (tree[i][0] > 0){
        post(tree[i][0]);
    }

    if (tree[i][1] > 0){
        post(tree[i][1]);
    }

    cout << (char)(i + 'A' - 1);

    return;
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n;
    memset(tree, 0, sizeof(tree));
    memset(visited, 0, sizeof(visited));

    for (int i = 0; i < n; i++){
        char n, l, r;
        cin >> n >> l >> r;
        int node = n - 'A' + 1;
        int lChild = l - 'A' + 1;
        int rChild = r - 'A' + 1;
        
        if (lChild > 0){
            tree[node][0] = lChild;
        }
        if (rChild > 0){
            tree[node][1] = rChild;
        }
    }

    for (int i = 1; i <= n; i++){
        if (!visited[i]){
            pre(i);
        }
    }
    cout << '\n';
    memset(visited, 0, sizeof(visited));

    for (int i = 1; i <= n; i++){
        if (!visited[i]){
            in(i);
        }
    }
    cout << '\n';
    memset(visited, 0, sizeof(visited));
    
    for (int i = 1; i <= n; i++){
        if (!visited[i]){
            post(i);
        }
    }

    return 0;
}