#include <bits/stdc++.h>
using namespace std;

vector<int> m[100];
vector<int> visited[100];

const int dy[4] = {-1, 0, 1, 0};
const int dx[4] = {0, 1, 0, -1};

int N,M;

void dfs(int y, int x) {
    int ny, nx;
    visited[y][x] = 1;

    cout << endl;
    for(int i = 0; i < N; i++) {\
        for(int j = 0; j < M; j++) {
            cout << visited[i][j] << " ";
        }
        cout << endl;
    }

    for(int i = 0; i < 4; i++) {
        ny = y + dy[i];
        nx = x + dx[i];
        if(ny < 0 || ny >= N || nx < 0 || nx >= M) continue;
        if(m[ny][nx] == 0) continue;
        if(visited[ny][nx] == 1) continue;
        dfs(ny, nx);
    }
    return;
}


int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    int temp, cnt=0;
    cin >> N >>  M;

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            cin >> temp;
            m[i].push_back(temp);
            visited[i].push_back(0);
        }
    }

    cout << endl;
    for(int i = 0; i < N; i++) {\
        for(int j = 0; j < M; j++) {
            cout << m[i][j] << " ";
        }
        cout << endl;
    }
    

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            if(m[i][j] == 0) continue;
            if(visited[i][j] == 1) continue;

            cout << i << ", " << j << " 시작합니다." << endl;
            dfs(i, j);
            cnt++;
        }
    }
    cout << cnt;
}