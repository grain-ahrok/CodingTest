#include <bits/stdc++.h>
using namespace std;

int main () {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);
    
    int N, K, p[11], cnt=0;
    cin >> N >> K; 

    for(int i = 0 ; i < N; i++) {
        cin >> p[i];
    }

    for(int i = N-1; i >= 0; i--) {
        if(K < p[i]) continue;
        cnt += K / p[i];
        K = K % p[i];
    }

    cout << cnt;


}