#include <bits/stdc++.h>
using namespace std;

void check() {

}

int main() {
    int N, M;
    cin >> N >> M;

    int res[1000001] = {};
    fill(res, res + M+1, 1);
    res[1] = 0;

    for(int i = 2; i <= M; i++) {
        if(res[i] == 0) continue;
        for(int j = 2; i * j<= M; j++) {
            res[i*j] = 0;
        }
    }

    for(int i = N; i <= M; i++) {
        if(res[i]) cout << i << "\n";
    }


}