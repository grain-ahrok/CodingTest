#include <bits/stdc++.h>
using namespace std;

int cp[130][130];
queue<pair<pair<int, int>, int>> q;
int b = 0, w = 0, N;

int main() {
    cin >> N;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            cin >> cp[i][j];
        }
    }
    q.push({{0,0}, N});
    int check, y, x, n, flag;

    while(q.size()){
        pair<pair<int, int>, int> item = q.front();
        q.pop();

        y = item.first.first;
        x = item.first.second;
        n = item.second;

        // cout << "{" << y << " : " << x <<"}   " << n <<"\n";

        check = cp[y][x];
        flag = 1;

        for(int i = y; i < y + n; i++ ){
            for(int j = x; j < x + n; j++) {

                if(check != cp[i][j]) {
                    q.push({{y, x}, n/2});
                    q.push({{y, x+(n/2)}, n/2});
                    q.push({{y+(n/2), x}, n/2});
                    q.push({{y+(n/2), x+(n/2)}, n/2});
                    flag = 0;
                    break;
                } 
            }
            if(flag == 0) {
                break;
            }
        }

        if(flag) {
            if(check == 1) {
                b++;
            }else {
                w++;
            }
        }


    }

    cout << w << "\n" << b <<"\n";
    
}