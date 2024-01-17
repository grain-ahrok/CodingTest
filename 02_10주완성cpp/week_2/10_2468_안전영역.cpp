#include <bits/stdc++.h>
using namespace std;

int N;
set<int> s;
vector<int> mmax;
int d[100][100] = {{0,},};
int m[100][100] = {{0,},};
int visited[100][100] = {{0,},};
int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};


void dfs(int y, int x) {
    visited[y][x] = 1;
    for(int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if(ny < 0 || ny >= N || nx < 0 || nx >= N) continue;
        if(m[ny][nx]) continue;
        if(visited[ny][nx]) continue;
        dfs(ny, nx);
    }
}

int main() {
    cin >> N;

    // 깊이 받아오기
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            cin >> d[i][j];
            s.insert(d[i][j]);
        }
    }

    for(int n = 0; n <= 100; n++) {
        // 깊이 맵 만들기
        for(int i = 0; i < N; i++) {
            for(int j = 0; j < N; j++) {
                // 안잠겼으면 0
                visited[i][j] = 0;
                m[i][j] = (d[i][j] - n) > 0 ? 0 : 1;
            }
        }

        int cnt = 0;
        for(int i = 0; i < N; i++) {
            for(int j = 0; j < N; j++) {
                if(visited[i][j] == 1) continue;
                if(m[i][j] == 1) continue;
                dfs(i, j);
                cnt++;
            }
        }
        mmax.push_back(cnt);
    }
    sort(mmax.begin(), mmax.end());
    cout << mmax.back();
}