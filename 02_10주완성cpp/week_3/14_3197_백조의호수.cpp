#include <bits/stdc++.h>
using namespace std;

int R,C; 
char smap[1500][1500];
int visited[1500][1500];
int L_visited[1500][1500];
queue<pair<int, int>> iceQ, iceQtemp, LQ, LQtemp;

int ans;
int y, x, ny, nx;
vector<pair<int, int>> L;
string temp;

const int dy[4] = {0, 1, 0, -1};
const int dx[4] = {-1, 0, 1, 0};

void QClear(queue<pair<int, int>> &q) {
    queue<pair<int, int>> empty;
    swap(q, empty);
}

// 
void melting() {

    while(iceQ.size()) {
        tie(y, x) = iceQ.front();
        iceQ.pop();

        for(int i = 0; i < 4; i++) {
            ny = y + dy[i];
            nx = x + dx[i];
            if(ny < 0 || ny >= R || nx < 0 || nx >= C || visited[ny][nx]) continue;
            if(smap[ny][nx] == 'X') {
                smap[ny][nx] = '.';
                iceQtemp.push({ny, nx});
                visited[ny][nx] = 1;
            }
        }
    }
}


// L1 -> L2를 만나는 지 확인
void bfs() {
    while(LQ.size()) {
        tie(y, x) = LQ.front();
        LQ.pop();
        L_visited[y][x] = 1;

        for(int i = 0; i < 4; i++) {
            ny = y + dy[i];
            nx = x + dx[i];

            if(ny < 0 || ny >= R || nx < 0 || nx >= C || L_visited[ny][nx]) continue;
            L_visited[ny][nx] = 1;
            if(smap[ny][nx] == 'X') LQtemp.push({ny, nx});
            else if(smap[ny][nx] == 'L' ) {
                cout << ans;
                exit(0);
            } else {
                LQ.push({ny, nx});
            }
        }
    }
    // cout << "\n";
    // for(int i = 0; i < R; i++) {
    //     for(int j = 0; j < C; j++) {
    //         cout << L_visited[i][j];
    //     }
    //     cout << "\n";
    // }
}


int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> R >> C;
    for(int i = 0; i < R; i++) {
        cin >> temp;
        for (int j = 0; j < C; j++){
            smap[i][j] = temp[j];
            if (temp[j] == 'L'){
                L.push_back({i, j});
            }
            if (temp[j] != 'X') {
                visited[i][j] = 1;
                iceQ.push({i, j});
            }
        }
    }

    pair<int, int> ll = L.front();
    LQ.push(ll);
    
    while(true) {
        

        // 백조가 움직일때
        bfs();
        melting();

        ans ++ ;
        LQ = LQtemp;
        QClear(LQtemp);
        iceQ = iceQtemp;
        QClear(iceQtemp);

        // cout << " \n";
        // for(int i = 0; i < R; i++) {
        //     for(int j = 0; j < C; j++) {
        //         cout << smap[i][j];
        //     }
        //     cout << "\n";
        // }
        
        // cout << "\n";
        // for(int i = 0; i < R; i++) {
        //     for(int j = 0; j < C; j++) {
        //         cout << visited[i][j];
        //     }
        //     cout << "\n";
        // }

        // cout << "\n";
        // for(int i = 0; i < R; i++) {
        //     for(int j = 0; j < C; j++) {
        //         cout << L_visited[i][j];
        //     }
        //     cout << "\n";
        // }

    }
}



/**
 * 
 * 
 *         cout << " \n";
        for(int i = 0; i < R; i++) {
            for(int j = 0; j < C; j++) {
                cout << smap[i][j];
            }
            cout << "\n";
        }
*/