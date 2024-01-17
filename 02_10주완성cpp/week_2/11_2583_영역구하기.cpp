#include <bits/stdc++.h>
using namespace std;

int M, N, K;
int m[100][100] = {{0,},};
int visited[100][100] = {{0,},};
int width = 0;
int dy[] = {1, 0, -1, 0};
int dx[] = {0, 1, 0, -1};
vector<int> ret;

void dfs(int y, int x){
    width ++;

    visited[y][x] = 1;
    for(int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if(ny < 0 || ny >= M || nx < 0 || nx >= N) continue;
        if(m[ny][nx]) continue;
        if(visited[ny][nx]) continue;
        dfs(ny, nx);
    }
}

int main () {
    cin >> M >> N >> K;

    // map 만들기
    int x1, y1, x2, y2;
    for(int i = 0; i < K; i++) {
        cin >> x1 >> y1 >> x2 >> y2;
        for(int k = y1; k < y2; k++) {
            for(int l = x1; l < x2; l++) {
                m[k][l] = 1;
            }
        }
    }

    
    // 깊이 탐색
    int cnt = 0;
    for(int i = 0; i < M; i++) {
        for(int j = 0; j < N; j++){
            if(m[i][j]) continue;
            if(visited[i][j]) continue;
            width = 0;
            dfs(i, j);
            ret.push_back(width);
            sort(ret.begin(), ret.end());
            cnt++;
        }
    }

    cout << cnt << endl;
    for(int i = 0; i < cnt; i++) {
        cout << ret[i] << " ";
    }
}