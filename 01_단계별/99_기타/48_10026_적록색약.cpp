#include <bits/stdc++.h>
using namespace std;

int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, -1, 0, 1};
char nmap[101][101];
int visited1[101][101] = {{0,},};
int visited2[101][101] = {{0,},};
int N;
int cnt1 = 0, cnt2 = 0;

void check1(int y, int x, char val) {
    visited1[y][x] = 1;
    int cy, cx;
    for(int i = 0 ; i < 4; i++) {
        cy = y + dy[i];
        cx = x + dx[i];
        if(visited1[cy][cx]) continue;
        if(cy < 0 || cx < 0 || cy >= N || cx >= N) continue;
        if(nmap[cy][cx] != val) continue;
        check1(cy, cx, val);
    }
}

void check2(int y, int x, char val) {
    visited2[y][x] = 1;
    int cy, cx;
    for(int i = 0 ; i < 4; i++) {
        cy = y + dy[i];
        cx = x + dx[i];
        if(visited2[cy][cx]) continue;
        if(cy < 0 || cx < 0 || cy >= N || cx >= N) continue;
        if(nmap[cy][cx] == val) {
            check2(cy, cx, val);
        } else if(val == 'B') {
            continue;
        } else if(val == 'R' && nmap[cy][cx] == 'G') {
            check2(cy, cx, val);
        } else if(val == 'G' && nmap[cy][cx] == 'R') {
            check2(cy, cx, val);
        }
        
    }
}


int main() {
    cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);

    cin >> N;
    string tmp;
    for(int i = 0; i < N; i++)  {
        cin >> tmp;
        for(int j = 0; j < N; j++){
            nmap[i][j] = tmp[j];
        }
    }


    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            if(visited1[i][j]) continue;
            cnt1++;
            check1(i, j, nmap[i][j]);
        }
    }

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            if(visited2[i][j]) continue;
            cnt2++;
            check2(i, j, nmap[i][j]);
        }
    }


    cout << cnt1 << " " << cnt2;


}