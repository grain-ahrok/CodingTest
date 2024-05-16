#include <bits/stdc++.h>
using namespace std;

int mmap[5][5];
int visited[5][5];
int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, -1, 0, 1};
int R, C, K;
int total = 0;


void dfs(int y, int x, int depth) {
    if(depth > K) return;
    if(y == 0 && x == C-1) return;

    for(int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];

        if(ny == 0 && nx == C-1 && depth+1 == K) {
            total++;
            return;
        }

        if(ny < 0 || ny >= R || nx < 0 || nx >= C) continue;
        if(visited[ny][nx] > 0 || mmap[ny][nx] == -1) continue;
        
        visited[ny][nx] = 1;
        dfs(ny, nx, depth + 1);
        visited[ny][nx] = 0;

    }
}


int main () {
    cin >> R >> C >> K;
    string temp;
    for(int i = 0; i < R; i++) {
        cin >> temp;
        for(int j = 0; j < C; j++) {
            if(temp[j] == 'T') {
                mmap[i][j] = -1;
            }
        }
    }

    
    visited[R-1][0] = 1;
    dfs(R-1, 0, 1);

    cout << total;

}