#include <bits/stdc++.h>
using namespace std;

int main () {
    int N, T, P;
    cin >> N;
    int sn[6];
    for(int i = 0; i < 6; i++) {
        cin >> sn[i];
    }
    cin >> T >> P;

    int cnt = 0;
    for(int i = 0; i < 6; i++) {
        cnt += sn[i] / T;
        if(sn[i] % T > 0) {
            cnt++;
        }
    }

    cout << cnt << "\n";
    cout << N/P << " " << N%P;


}