#include <bits/stdc++.h>
using namespace std; 

int main () {
    int N;
    int val[300001];
    int tmp = 0;

    cin >> N;
    for(int i = 0; i < N; i++) {
        cin >> val[i];
        tmp += val[i];
        val[i] = tmp;
    }

    // for(int i = 0; i < N; i++) {
    //     cout << val[i] << " ";
    // }

    int rmN = round(N*0.15);
    int res = round((double)(val[N-rmN-1] - val[rmN-1]) / (N-rmN*2));
    cout << val[N-rmN-1] - val[rmN-1] << " ";
    cout << res;
}