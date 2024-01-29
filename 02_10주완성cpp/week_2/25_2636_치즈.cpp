#include <bits/stdc++.h>
using namespace std;

int N,M;
int init[100][100] = {{0,},};
int visited[100][100] = {{0,},};
int c_time = 0, ccnt = 0, cprev;
int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};


void dfs(int y, int x) {
    visited[y][x] = 1;
    for(int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if(ny < 0 || ny >= N || nx < 0 || nx >= M) continue;
        if(visited[ny][nx]) continue;

        // ?? ?? ? ???, ??? ?? ?
        if(init[ny][nx] == 1) {
            visited[ny][nx] = 1;
            init[ny][nx] = 0;
            ccnt++;
        } else {
            dfs(ny, nx);
        }
    }
}

void print() {
    for(int i = 0 ; i < N; i++) {
        for(int j = 0; j < M; j++) {
            cout << init[i][j] <<  " ";
        }
        cout << "\n";
    }
    cout << "\n";
}

void init_visit(int idx) {
    for(int i = idx; i < N-idx; i++) {
        for(int j = idx; j < M-idx; j++) {
            visited[i][j] = 0;
        }
    }
}

int main() {
    cin >> N >> M;

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            cin >> init[i][j];
        }
    }


    do {
        cprev = ccnt;
        init_visit(c_time);
        ccnt = 0;
        dfs(c_time, c_time);
        c_time++;
    } while(ccnt);

    cout << c_time-1 << "\n";
    cout << cprev;
    return 0;
}