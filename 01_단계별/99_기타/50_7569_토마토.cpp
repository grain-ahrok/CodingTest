#include <bits/stdc++.h>
using namespace std;

int N, M, O;
int tomato[101][101][101];
int dz[6] = {0, 0, 0, 0, 1, -1};
int dy[6] = {-1, 0, 1, 0, 0, 0};
int dx[6] = {0, -1, 0, 1, 0, 0};

queue<tuple<int, int, int>> q;

int main() {

    cin >> M >> N >> O;
    for(int k = 0; k < O; k++){
        for(int i = 0; i < N; i++) {
            for(int j = 0; j < M; j++) {
                cin >> tomato[k][i][j];
                if(tomato[k][i][j] == 1) {
                    q.push({k, i, j});
                }
            }
        }
    }
    

    int z, y, x, cz, cy, cx, cnt = 1;
    while(q.size()) {
        z = get<0>(q.front());
        y = get<1>(q.front());
        x = get<2>(q.front());
        q.pop();


        for(int i = 0; i < 6; i++) {
            cz = z + dz[i];
            cy = y + dy[i];
            cx = x + dx[i];
            if(cz < 0 || cy < 0 || cx < 0 || cz >= O || cy >= N || cx >= M) continue;
            if(tomato[cz][cy][cx]) continue;
            if(tomato[cz][cy][cx] == -1) continue;
            tomato[cz][cy][cx] = tomato[z][y][x] + 1;
            cnt = max(tomato[cz][cy][cx], cnt);
            q.push({cz, cy, cx});
        }
    }

    int check = 1;
    for(int k = 0; k < O; k++) {
        for(int i = 0; i < N; i++) {
            for(int j = 0; j < M; j++) {
                if(tomato[k][i][j] == 0) {
                    check = 0;
                    break;
                }
            }
        }
    }
    
    if(check){
        cout << cnt - 1;
    } else {
        cout << -1;
    }




}