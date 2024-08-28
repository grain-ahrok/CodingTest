#include <bits/stdc++.h>
using namespace std;

int N, M;
int tomato[1001][1001];
int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, -1, 0, 1};

queue<pair<int,int>> q;

int main() {

    cin >> M >> N;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            cin >> tomato[i][j];
            if(tomato[i][j] == 1) {
                q.push({i, j});
            }
        }
    }

    int y, x, cy, cx, cnt = 1;
    while(q.size()) {
        y = q.front().first;
        x = q.front().second;

        q.pop();
        for(int i = 0; i < 4; i++) {
            cy = y + dy[i];
            cx = x + dx[i];
            if(cy < 0 || cx < 0 || cy >= N || cx >= M) continue;
            if(tomato[cy][cx]) continue;
            if(tomato[cy][cx] == -1) continue;
            tomato[cy][cx] = tomato[y][x] + 1;
            cnt = max(tomato[cy][cx], cnt);
            q.push({cy, cx});
        }
    }

    int check = 1;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            if(tomato[i][j] == 0) {
                check = 0;
                break;
            }
        }
    }
    if(check){
        cout << cnt - 1;
    } else {
        cout << -1;
    }




}