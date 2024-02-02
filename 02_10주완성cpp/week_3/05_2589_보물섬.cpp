#include <bits/stdc++.h>
using namespace std;

int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};

int N, M;
int cmap[50][50] = {{0,},};
int visited[50][50] = {{0,},};
string temp;
int cmax = 0;


void print() {
    cout << endl;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            cout << visited[i][j] << " ";
        }
        cout << endl;
    }
}


int bfs(int y, int x) {

    int tempMax = 0;
    queue<pair<int, int>> q;
    q.push({y, x});
    visited[y][x] = 1;

    while(q.size()) {
        pair<int, int> here = q.front();
        q.pop();
        for(int i = 0; i < 4; i++) {
            int ny = here.first + dy[i];
            int nx = here.second + dx[i];
            if(ny < 0 || ny >= N || nx < 0 || nx >= M) continue;
            if(visited[ny][nx]) continue;
            if(cmap[ny][nx] == 0) continue;
            q.push({ny, nx});
            visited[ny][nx] = visited[here.first][here.second] + 1;
            if(visited[ny][nx]-1 > tempMax) tempMax = visited[ny][nx]-1;
        }
    }
    return tempMax;
}




int main() {
    cin.tie(NULL); cout.tie(NULL);
    cin >> N >> M;

    for(int i = 0; i < N; i++) {
        cin >> temp;
        for(int j = 0; j < temp.length(); j++) {
            cmap[i][j] = (temp[j] == 'W') ? 0 : 1;
        }
    }

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            if(cmap[i][j] == 0) continue;
            int ibfs = bfs(i, j);
            if(cmax < ibfs) cmax = ibfs;
            for(int k = 0; k < N; k++) for(int l = 0; l < M; l++) visited[k][l] = 0;
        }
    }

    cout << cmax;
    return 0;
}