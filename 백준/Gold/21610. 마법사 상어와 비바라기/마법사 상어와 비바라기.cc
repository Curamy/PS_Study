#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;
int height[50][50];
vector<pair<int, int>> position;
vector<pair<int, int>> tmp;
int dy[8] = {0, -1, -1, -1, 0, 1, 1, 1};
int dx[8] = {-1, -1, 0, 1, 1, 1, 0, -1};

void move(int dir, int dist){
    for (auto& pos : position){
        int y = pos.first;
        int x = pos.second;

        for (int d = 0; d < dist; d++){
            y += dy[dir];
            x += dx[dir];
            
            if (y < 0){
                y = N - 1;
            }
            if (y == N){
                y = 0;
            }
            if (x < 0){
                x = N - 1;
            }
            if (x == N){
                x = 0;
            }
        }

        pos.first = y;
        pos.second = x;
    }
}

void inject(){
    for (auto pos : position){
        int y = pos.first;
        int x = pos.second;
        height[y][x]++;
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
    for (auto pos : position){
        tmp.push_back(pos);
    }
    position.clear();

    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            if (height[i][j] >= 2){
                bool isCut = true;
                for (auto t : tmp){
                    if (i == t.first && j == t.second){
                        isCut = false;
                        break;
                    }
                }
                if (isCut){
                    height[i][j] -= 2;
                    position.push_back({i, j});
                }
            }
        }
    }

    tmp.clear();
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