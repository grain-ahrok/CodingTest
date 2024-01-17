#include <bits/stdc++.h>
using namespace std;

int T, N, M, veg;
int m[50][50] = {{0,},};
int visited[50][50] = {{0,},};
int cnt;
int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};


void dfs(int y, int x) {
    visited[y][x] = 1;
    for(int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if(ny < 0 || ny >= N || nx < 0 || nx >= M) continue;
        if(m[ny][nx] == 0) continue;
        if(visited[ny][nx]) continue;
        dfs(ny, nx);
    }
}


int main() {
    cin >> T;

    while(T) {
        cin >> N >> M >> veg;
        fill(&m[0][0], &m[N-1][M-1], 0);
        fill(&visited[0][0], &visited[N-1][M-1], 0);
        cnt = 0;

        int ty, tx;
        for(int i = 0; i < veg; i++) {
            cin >> ty >> tx;
            m[ty][tx] = 1;
        }

        for(int i = 0; i < N; i++) {
            for(int j = 0; j < M; j++) {
                if(m[i][j] == 0) continue;
                if(visited[i][j]) continue;
                dfs(i, j);
                cnt++;
            }
        }

        cout << cnt << endl;
        T--;
    }


}