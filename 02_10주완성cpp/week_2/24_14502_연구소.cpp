#include <bits/stdc++.h>
using namespace std;


int N, M;
int init[8][8] = {{0, },};
// 방문여부를 담음.
int v_visited[8][8] = {{0, },};
// 그때그때의 확산결과를 담음.
int temp[8][8] = {{0, },};
int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};
vector<pair<int, int>> walls;
int cnt = 0, cmax = 0;

void dfs(int y, int x) {
    temp[y][x] = 2;
    for(int i = 0; i < 4; i++) {
        for(int j = 0; j < 4; j++) {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if(ny < 0 || ny >= N || nx < 0 || nx >= M) continue;
            if(temp[ny][nx]) continue;
            dfs(ny, nx);
        }
    }
}

int safe_zone(){
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            temp[i][j] = init[i][j];
        }
    }
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            if(temp[i][j] == 1 || temp[i][j] == 0) continue;
            dfs(i, j);
        }
    }
    int total = 0;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            if(temp[i][j] == 0) total++;
        }
    }
    return total;
}   


int main(){
    cin.tie(NULL); cout.tie(NULL);
    cin >> N >> M;

    // 1. 입력을 받는다.
    // 1-1. 0인 부분은 따로 저장한다.
    for (int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            cin >> init[i][j];
            if(init[i][j] == 0) {
                walls.push_back({i, j});
            }
        }
    }
    

    // 2. 조합으로 벽을 세운다. 
    for(int i = 0; i < walls.size()-2; i++) {
        for(int j = i+1; j < walls.size()-1; j++) {
            for(int k = j+1; k < walls.size(); k++) {
                init[walls[i].first][walls[i].second] = 1;
                init[walls[j].first][walls[j].second] = 1;
                init[walls[k].first][walls[k].second] = 1;

                int sz = safe_zone();
                if(sz > cmax) {
                    cmax = sz;
                }

                init[walls[i].first][walls[i].second] = 0;
                init[walls[j].first][walls[j].second] = 0;
                init[walls[k].first][walls[k].second] = 0;
            }
        }
    }

    cout << cmax;

    
    // 3. 순열을 하나씩 꺼내어 BFS로 바이러스를 퍼뜨린다.
        // 3-1. 0인 부분을 센다.
        // 3-2. 최댓값을 뽑는다.


}