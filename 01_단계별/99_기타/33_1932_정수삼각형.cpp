#include <bits/stdc++.h>
using namespace std;

vector<int> num[501];
int nmax[501][501];
int N; 


int main() {
    cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);
    cin >> N;
    int temp;

    for(int i = 0; i < N; i++) {
        for(int j = 0; j <i+1; j++ ) {
            cin >> temp;
            num[i].push_back(temp);
        }
    }

    nmax[0][0] = num[0][0];
    for(int i = 1; i < N; i++) {
        for(int j = 0; j < i+1; j++) {
            if(j == 0) {
                nmax[i][j] = num[i][j] + nmax[i-1][j];
            } else if(j == i){
                nmax[i][j] = num[i][j] + nmax[i-1][j-1];
            } else {
                nmax[i][j] = num[i][j] + max(nmax[i-1][j-1], nmax[i-1][j]);
            }
        }
    }

    int res = 0;
    for(int i = 0; i < N; i++) {
        res = max(nmax[N-1][i], res);
    }

    cout << res;
    
}