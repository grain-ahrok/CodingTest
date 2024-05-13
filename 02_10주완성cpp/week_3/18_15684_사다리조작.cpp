#include <bits/stdc++.h>
using namespace std;

int N, M, H;
int mmap[32][12];
vector<pair<int, int>> v;

// go letter!!
int go(int y, int x) {
    int kstart = x;
    
    while(true) {
        if(y > H) {
            if(x == kstart) {
                return 1;
            } else {
                
                return -1;
            }
        }
        
        if(mmap[y][x] == 1) {
            x += 1;
            y += 1;
        } else if(x >= 2 && mmap[y][x-1] == 1) {
            x -= 1;
            y += 1;
        } else {
            y += 1;
        }
    }

}


int main() {
    cin >> N >> M >> H;

    int tempy, tempx;
    for(int i = 0; i < M; i++) {
        cin >> tempy >> tempx;
        mmap[tempy][tempx] = 1;
    }


    // 0
    int check = true;
    for(int i = 1; i < N; i++) {
        tempx = go(1, i);
        if(tempx == -1) {
            check = false;
            break;
        };
        
    }
    if(check) {
        cout << 0;
        exit(0);
    }

    for(int i = 1; i <= H; i++) {
        for(int j = 1; j < N; j++) {
            if(mmap[i][j-1] != 1 && mmap[i][j+1] != 1 && mmap[i][j] == 0) {
                v.push_back({i, j});
            } 
        }
    }


    // 1
    for(int i = 0; i < v.size(); i++) {
        check = true;
        mmap[v[i].first][v[i].second] = 1;
        
        for(int j = 1; j < N; j++) {
            if(go(1, j) == -1) {
                check = false;
                break;
            }
        }
        if(check) {
            cout << 1;
            exit(0);
        }
        mmap[v[i].first][v[i].second] = 0;
    }


    // 2
    for(int i = 0; (i < v.size()-1) && v.size() >= 2; i++) {
        mmap[v[i].first][v[i].second] = 1;

        for(int j = i + 1; j < v.size(); j++) {
            if((v[i].first == v[j].first) && (v[i].second-v[j].second == 1 || v[i].second-v[j].second == -1)) continue;
            mmap[v[j].first][v[j].second] = 1;

            check = true;
            for(int k = 1; k < N; k++) {
                if(go(1, k) == -1) {
                    check = false;
                    break;
                }
            }

            if(check) {
                cout << 2;
                exit(0);
            }
            mmap[v[j].first][v[j].second] = 0;
        }
        mmap[v[i].first][v[i].second] = 0;
    }


    // 3
    for(int i = 0; i < (v.size()-2) && v.size() >= 3; i++) {
        mmap[v[i].first][v[i].second] = 1;

        for(int j = i+1; j < v.size()-1; j++) {
            if((v[i].first == v[j].first) && (v[i].second-v[j].second == 1 || v[i].second-v[j].second == -1)) continue;
            mmap[v[j].first][v[j].second] = 1;

            for(int k = j+1; k < v.size(); k++) {
                if((v[i].first == v[k].first) && (v[i].second-v[k].second == 1 || v[i].second-v[k].second == -1)) continue;
                if((v[j].first == v[k].first) && (v[j].second-v[k].second == 1 || v[j].second-v[k].second == -1)) continue;
                mmap[v[k].first][v[k].second] = 1;

                check = true;
                for(int l = 1; l < N; l++) {
                if(go(1, l) == -1) {
                    check = false;
                    break;
                    }
                }

                if(check) {
                    cout << 3;
                    exit(0);
                }

                mmap[v[k].first][v[k].second] = 0;
            }
            mmap[v[j].first][v[j].second] = 0;
        }
        mmap[v[i].first][v[i].second] = 0;
    }

    cout << -1;
}