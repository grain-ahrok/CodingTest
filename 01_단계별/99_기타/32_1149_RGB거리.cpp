#include <bits/stdc++.h>
using namespace std;

int N;
int rgb[1001][3] = {{0,},};
int res[1001][3] = {{0,},};

int main() {

    cin >> N;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < 3; j++) {
            cin >> rgb[i][j];
        }
    }

    res[0][0] = rgb[0][0];
    res[0][1] = rgb[0][1];
    res[0][2] = rgb[0][2];
    for(int i = 1; i < N; i++) {
        res[i][0] = min(res[i-1][1], res[i-1][2]) + rgb[i][0];
        res[i][1] = min(res[i-1][2], res[i-1][0]) + rgb[i][1];
        res[i][2] = min(res[i-1][0], res[i-1][1]) + rgb[i][2];
    }
    cout << min(res[N-1][0], min(res[N-1][1], res[N-1][2]));


}