#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;
int height[50][50];
bool isCut[50][50];
vector<pair<int, int>> position;
int dy[8] = {0, -1, -1, -1, 0, 1, 1, 1};
int dx[8] = {-1, -1, 0, 1, 1, 1, 0, -1};

void move(int dir, int dist){
    for (auto& pos : position){
        int y = pos.first;
        int x = pos.second;

        y = (y + dy[dir] * (dist % N) + N * 50) % N;
        x = (x + dx[dir] * (dist % N) + N * 50) % N;

        pos.first = y;
        pos.second = x;

        isCut[y][x] = true;
    }
}

void inject(){
    for (auto pos : position){
        height[pos.first][pos.second]++;
    }
}

void grow(){
    for (auto pos : position){
        int y = pos.first;
        int x = pos.second;
        
        int ddy[4] = {-1, 1, 1, -1};
        int ddx[4] = {1, 1, -1, -1};
        int num = 0;

        for (int i = 0; i < 4; i++){
            int ny = y + ddy[i];
            int nx = x + ddx[i];

            if (ny < 0 || ny == N || nx < 0 || nx == N){
                continue;
            }

            if (height[ny][nx] >= 1){
                num++;
            }
        }

        height[y][x] += num;
    }
}

void cut(){
    vector<pair<int, int>> next_position;

    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            if (isCut[i][j]) {
                isCut[i][j] = false;
            }

            else if (height[i][j] >= 2) {
                height[i][j] -= 2;
                next_position.push_back({i, j});
            }
        }
    }

    position = next_position;
}

void debug(){
    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            cout << height[i][j] << " ";
        }
        cout << "\n";
    }
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> N >> M;
    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            cin >> height[i][j];
        }
    }

    position.push_back({N - 1, 0});
    position.push_back({N - 1, 1});
    position.push_back({N - 2, 0});
    position.push_back({N - 2, 1});

    for (int m = 0; m < M; m++){
        int dir, dist;
        cin >> dir >> dist;
        
        move(dir - 1, dist);
        inject();
        grow();
        cut();
    }

    int ans = 0;
    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            ans += height[i][j];
        }
    }

    cout << ans;

    return 0;
}