#include <bits/stdc++.h>
using namespace std;

int N, M;
int visited[100][100] = {{0,},};
int m[100][100] = {{0,},};
int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};

void bfs() {
    queue<pair<int, int>> q;
    q.push({0, 0});

    while(q.size()) {
        int y = q.front().first;
        int x = q.front().second;
        q.pop();

        for(int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if(ny < 0 || ny >= N || nx < 0 || nx >= M) continue;
            if(m[ny][nx] == 0) continue;
            if(visited[ny][nx]) continue;
            visited[ny][nx] = visited[y][x] + 1;
            q.push({ny, nx});
        }
    }
}

int main() {
    cin >> N >> M;
    string Nstr;
    for(int i = 0; i < N; i++) {
        cin >> Nstr;
        for(int j = 0; j < M; j++) {
            m[i][j] = Nstr[j] - '0';
        }
    }

    bfs();
    cout << visited[N-1][M-1] + 1;

}