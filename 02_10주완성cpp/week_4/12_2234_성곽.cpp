#include <bits/stdc++.h>
using namespace std;

int N, M;
int nmap[51][51] = {{0,},};
int visited[51][51] = {{0,},};
int roomMaxValue = 0;
int roomCnt = 0;

int dy[4] = {0, -1, 0, 1};
int dx[4] = {-1, 0, 1, 0};

int big = 0;
int compValue[2501] = {0, };

void bfs(int n, int m) {
    int cnt = 1;
    queue<pair<int, int>> q;
    q.push({n,m});
    
    while(q.size()) {
        int y = q.front().first;
        int x = q.front().second;
        q.pop();
        int num = nmap[y][x];

        for(int i = 0; i < 4; i++) {
            // 벽으로 막혀있거나 방문 흔적이 있으면 무시
            if(((num>>i)&1)==1) continue;
            int ny = y + dy[i];
            int nx = x + dx[i];
            if(visited[ny][nx]) continue;

            // 방문 하는 경우
            visited[ny][nx] = roomCnt;
            q.push({ny, nx});
            cnt++;
        }
    }
    compValue[roomCnt] = cnt;
    roomMaxValue = max(cnt, roomMaxValue);
}


int main() {
    cin >> M >> N;
    
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            cin >> nmap[i][j];
        }
    }
   
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            if(visited[i][j]) continue;
            roomCnt++;
            visited[i][j] = roomCnt;
            bfs(i, j);
        }
    }

    for(int i = 0; i < N-1; i++) {
        for(int j = 0; j < M; j++) {
            if(visited[i][j] != visited[i+1][j]) {
                big = max(big, compValue[visited[i][j]] + compValue[visited[i+1][j]]);
            }
        }
    }
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M-1; j++) {
            if(visited[i][j] != visited[i][j+1]) {
                big = max(big, compValue[visited[i][j]] + compValue[visited[i][j+1]]);

            }
        }
    }

    cout << roomCnt << "\n" << roomMaxValue << "\n" << big;
}
