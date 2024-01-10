#include <bits/stdc++.h>
using namespace std;

int m[100][100] = {{0,},};
int visited[100][100] = {{0,},};
int N, M;
int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};

// or "pair<int, int>" 사용할 수 있다.
struct cor {
    int y;
    int x;
};

void bfs(struct cor here) {
    queue<struct cor> q;
    visited[here.y][here.x] = 1;
    q.push(here);

    while(q.size()) {
        struct cor here = q.front();
        q.pop();
        for(int i = 0; i < 4; i++) {
            int ny = here.y + dy[i];
            int nx = here.x + dx[i];
            //TODO : under floor, over floor 체크
            if(ny < 0 || ny >= N || nx < 0 || nx >= M) continue;
            if(m[ny][nx] == 0) continue;
            if(visited[ny][nx]) continue;
            visited[ny][nx] = visited[here.y][here.x] + 1;
            q.push({ny, nx});
        }
    }

}


int main() {
    struct cor one;
    struct cor carrot;
    cin >> N >> M;
    cin >> one.y >> one.x;
    cin >> carrot.y >> carrot.x;

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            cin >> m[i][j];
        }
    }
    bfs(one);


    cout << endl;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            cout << visited[i][j] << " ";
        }
        cout << endl;
    }
}

