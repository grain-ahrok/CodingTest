#include <bits/stdc++.h>
using namespace std;

int R, C;
int wall_map[1000][1000] = {{0,}, };
int jihoon_map[1000][1000] = {{0,},};
int fire_map[1000][1000] = {{0,},};
pair<int, int> jihoon;
vector<pair<int, int>> fire;
vector<int> ret;

int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};

void print_wall() {
    cout << "### WALL ###" << "\n";
    for(int i = 0; i < R; i++ ) {
        for(int j = 0; j < C; j++) {
            cout << wall_map[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "\n";
}

void print_fire() {
    cout << "### FIRE ###" << "\n";
    for(int i = 0; i < R; i++ ) {
        for(int j = 0; j < C; j++) {
            cout << fire_map[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "\n";
}

void print_jihoon() {
    cout << "### JIHOON ###" << "\n";
    for(int i = 0; i < R; i++ ) {
        for(int j = 0; j < C; j++) {
            cout << jihoon_map[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "\n";
}

int main() {
    
    string temp;
    cin >> R >> C;
    for(int i = 0; i < R; i++) {
        cin >> temp;
        for(int j = 0; j < C; j++) {
            wall_map[i][j] = temp[j] == '#' ? -1 : 0;
            if(temp[j] == 'J') jihoon = {i, j};
            else if(temp[j] == 'F') fire.push_back({i, j});
        }
    }

    // fire bfs
    for(auto it : fire) {
        queue<pair<int, int>> v;
        v.push(it);
        fire_map[it.first][it.second] = 1;

        while(v.size()) {
            pair<int, int> here = v.front();
            v.pop();
            for(int i = 0; i < 4; i++) {
                int ny = here.first + dy[i];
                int nx = here.second + dx[i];
                if(ny < 0 || ny >= R || nx < 0 || nx >= C) continue;
                if(wall_map[ny][nx] == -1) continue;
                if(fire_map[ny][nx] > 0 && fire_map[ny][nx] <= fire_map[here.first][here.second] + 1) continue;
                fire_map[ny][nx] = fire_map[here.first][here.second] + 1;
                v.push({ny, nx});
            }
        }
        
    }
    // print_fire();

    // jihoon bfs
    queue<pair<int, int>> v;
    v.push({jihoon.first, jihoon.second});
    jihoon_map[jihoon.first][jihoon.second] = 1;
    while(v.size()) {
        pair<int, int> here = v.front();
        v.pop();

        for(int i = 0; i < 4; i++) {
            int ny = here.first + dy[i];
            int nx = here.second + dx[i];
            if(ny < 0 || ny >= R || nx < 0 || nx >= C) continue;
            if(wall_map[ny][nx] == -1) continue;
            if(jihoon_map[ny][nx]) continue;
            if(fire_map[ny][nx] != 0 && jihoon_map[here.first][here.second] + 1 >= fire_map[ny][nx]) continue;
            jihoon_map[ny][nx] = jihoon_map[here.first][here.second] + 1;
            v.push({ny, nx});
        }
        // print_jihoon();
    }

    for(int i = 0; i < R; i++) {
        if(jihoon_map[i][0] > 0) {
            ret.push_back(jihoon_map[i][0]);
        }
        if(jihoon_map[i][C-1] > 0) {
            ret.push_back(jihoon_map[i][C-1]);
        }
    }

    for(int j = 1; j < C-1; j++) {
        if(jihoon_map[0][j] > 0) {
            ret.push_back(jihoon_map[0][j]);
        }
        if(jihoon_map[R-1][j] > 0) {
            ret.push_back(jihoon_map[R-1][j]);
        }
    }

    if(ret.size() == 0) {
        cout << "IMPOSSIBLE";
    } else {
        sort(ret.begin(), ret.end());
        cout << ret[0];
    }
    
    return 0;
}