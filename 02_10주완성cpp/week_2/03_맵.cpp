#include <bits/stdc++.h>
using namespace std;
// 위 오른쪽 아래 왼쪽
int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};
int m[3][3] = {{0, },};

int visited[3][3] = {{0, },};

void go(int y, int x) {
    int ny = y, nx = x;
    visited[y][x] = 1;
    cout << y << " : " << x << endl;

    for(int i = 0; i < 4; i++) {
        ny = y + dy[i];
        nx = x + dx[i];
        if(ny < 0 || ny > 2 || nx < 0 || nx > 2) continue;
        if(visited[ny][nx]) continue;
        if(m[ny][nx] == 0) continue;
            go(ny, nx);
    } 
}

int main() {
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            cin >> m[i][j];
        }
    }
    go(0, 0);
    return 0;
}