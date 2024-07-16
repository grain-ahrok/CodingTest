#include <bits/stdc++.h>
using namespace std;

int main() {
    int res[12] = {0,};
    res[1] = 1;
    res[2] = 2;
    res[3] = 4;

    for(int i = 4; i < 12; i++) {
        res[i] = res[i-3]+ res[i-2] + res[i-1];
    }

    int N, temp;
    cin >> N;
    for(int i = 0; i < N; i++) {
        cin >> temp;
        cout << res[temp] << "\n";
    }

}