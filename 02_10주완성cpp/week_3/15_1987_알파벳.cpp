#include <bits/stdc++.h>
using namespace std;

vector<char> v;
char smap[20][20];
int R, C;
int total_max;
int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, -1, 0, 1};


void dfs(int y, int x) {
    total_max = max(total_max, (int)v.size());

    // for(auto c : v) {
    //     cout << c << " ";
    // }
    // cout << " \n";

    for(int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if(ny < 0 || ny >= R || nx < 0 || nx >= C) continue;
        if(find(v.begin(), v.end(), smap[ny][nx]) == v.end()) {  // 원소가 안에 없는 경우
            v.push_back(smap[ny][nx]);
            dfs(ny, nx);
            v.pop_back();
        } 
    }

}


int main() {

    cin >> R >> C;
    string temp;
    for(int i = 0; i < R; i++) {
        cin >> temp;
        for(int j = 0; j < C; j++) {
            smap[i][j] = temp[j];
        }
    }

    v.push_back(smap[0][0]);
    dfs(0, 0);

    cout << total_max;



}