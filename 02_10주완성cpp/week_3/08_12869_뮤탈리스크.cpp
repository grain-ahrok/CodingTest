#include <bits/stdc++.h>
using namespace std;

int visited[64][64][64];
int scv[3];
int N;
int ret = 60;
int d[6][3] = {
    {9, 3, 1},
    {9, 1, 3},
    {3, 9, 1},
    {3, 1, 9},
    {1, 9, 3},
    {1, 3, 9}
};

struct S{
    int a, b, c;
};


int main() {
    cin >> N;

    for(int i = 0; i < N; i++) {
        cin >> scv[i];
    }
    if(N == 1) {
        visited[scv[0]][0][0] = 1;
    } else if(N == 2)  {
        visited[scv[0]][scv[1]][0] = 1;
    } else {
        visited[scv[0]][scv[1]][scv[2]] = 1;
    }
    

    queue<S> q;
    q.push({scv[0], scv[1], scv[2]});

    while(q.size()) {
        struct S here = q.front();
        q.pop();
        for(int i = 0; i < 6; i++) {
            struct S _new = {
                here.a-d[i][0] >= 0 ? here.a-d[i][0] : 0,
                here.b-d[i][1] >= 0 ? here.b-d[i][1] : 0,
                here.c-d[i][2] >= 0 ? here.c-d[i][2] : 0,
            };
            if(visited[_new.a][_new.b][_new.c]) continue;
            if(_new.a == 0 && _new.b == 0 && _new.c == 0) {
                cout << visited[here.a][here.b][here.c];
                return 0;
            }
            visited[_new.a][_new.b][_new.c] = visited[here.a][here.b][here.c] + 1;
            q.push({_new.a, _new.b, _new.c});
        }
    };
    
}