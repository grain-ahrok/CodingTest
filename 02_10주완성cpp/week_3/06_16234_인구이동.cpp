#include <bits/stdc++.h>
using namespace std;

int N, L, R;
int cmap[50][50] = {{0,},};

int total_visited[50][50] = {{0,},};
int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};



void print() {
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            cout << cmap[i][j] << " ";
        }
        cout << "\t\t";
        for(int j = 0; j < N; j++) {
            cout << total_visited[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "\n\n";
}


int dfs(int y, int x) {

    vector<pair<int, int>> visited;
    queue<pair<int, int>> v;
    int people = cmap[y][x];
    int count = 1;
    v.push({y, x});
    visited.push_back({y, x});
    total_visited[y][x] = 1;

    while(v.size()) {
        pair<int, int> here = v.front();
        v.pop();
        for(int i = 0; i < 4; i++) {
            int ny = here.first + dy[i];
            int nx = here.second + dx[i];
            if(ny < 0 || ny >= N || nx < 0 || nx >= N) continue;
            if(total_visited[ny][nx]) continue;

            int temp = abs(cmap[ny][nx] - cmap[here.first][here.second]);
            if(temp < L || temp > R) continue;

            v.push({ny, nx});
            total_visited[ny][nx] = 1;
            visited.push_back({ny, nx});
            people += cmap[ny][nx];
            count++;
        }
        
    }
    int cal = people / count;
    for(auto it : visited){
        cmap[it.first][it.second] = cal;
    }

    // print();
    return count-1;
}


int main() {
    cin >> N >> L >> R;

    int day = 0;

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            cin >> cmap[i][j];
        }
    }
    
    while(true){
        int isChanged = 0;
        for(int i = 0; i < N; i++) {
            for(int j = 0; j < N; j++ ) {
                if(total_visited[i][j]) continue;
                isChanged += dfs(i, j);
            }
        }

        for(int i = 0; i < N; i++) {
            for(int j = 0; j < N; j++) {
                total_visited[i][j] = 0;
            }
        }
        if(isChanged) day ++;
        else break;

    }

    
    cout << day;
    return 0;
}