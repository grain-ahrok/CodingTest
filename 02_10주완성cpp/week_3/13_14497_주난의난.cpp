#include <bits/stdc++.h>
using namespace std;

int visited[300][300];
char smap[300][300];
int total_cnt = 0;
int N, M;

int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, -1, 1};

struct cor {
    int y;
    int x;
};


void dfs(int y, int x) {
    visited[y][x] = 1;
    if(smap[y][x] == '1') {
        smap[y][x] = '0';
        return;
    } else if (smap[y][x] == '#') {
        cout << total_cnt;
        exit(0);
    }

    for(int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];

        if(ny < 0 || ny >= N || nx < 0 || nx >= M) continue;
        if(visited[ny][nx] == 1) continue;
        dfs(ny, nx);
    }

}


int main() {

    struct cor junan;
    struct cor chocolate;

    string str;
    cin >> N >> M;
    cin >> junan.y >> junan.x >> chocolate.y >> chocolate.x;
    junan.y--; junan.x--; chocolate.y--;chocolate.x--;

    for(int i = 0; i < N; i++) {
        cin >> str;
        for(int j = 0; j < M; j++) {
            smap[i][j] = str[j];
        }
    }

    while(true) {
        total_cnt++;
        for(int i = 0; i < N; i++) {
            for(int j = 0; j < M; j++) {
                visited[i][j] = 0;
            }
        }

        dfs(junan.y, junan.x);
    }

}
