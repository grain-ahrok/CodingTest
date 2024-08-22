#include <bits/stdc++.h>
using namespace std;

int N, M;
int dy[4] = {0, -1, 0, 1};
int dx[4] = {-1, 0, 1, 0};
int visited[600][600] = {{0,},};
int nmap[600][600] = {{0,},};
int res = 0; 

int main() {
    cin >> N >> M;
    char tmp;

    pair<int, int> doyeon;

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            cin >> tmp;
            if(tmp == 'P') {
                nmap[i][j] = 1;
            } else if(tmp == 'X') {
                nmap[i][j] = -1;
            } else if(tmp == 'I'){
                doyeon.first = i;
                doyeon.second = j;
                visited[i][j] = 1;
            }
        }
    }

    queue<pair<int, int>> q;
    q.push({doyeon.first, doyeon.second});

    while(q.size()) {
        pair<int, int> cur = q.front();
        q.pop();
        for(int i = 0; i < 4; i++) {
            int y = cur.first + dy[i];
            int x = cur.second + dx[i];
            if(y < 0 || y >= N || x < 0 || x >= M) continue;
            if(visited[y][x] || nmap[y][x] == -1) continue;
            visited[y][x] = 1;
            q.push({y, x});
            if(nmap[y][x] == 1) res++;
        }
    }

    if(res) {
        cout << res;
    } else {
        cout << "TT";
    }


}


