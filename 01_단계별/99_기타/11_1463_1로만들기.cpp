#include <bits/stdc++.h>
using namespace std;

int main() {

    int N;
    cin >> N;
    int m[N+1];
    fill_n(m, N+1, 0);
    m[1] = 0;
    m[2] = 1;
    m[3] = 1;
    m[4] = 2;
    m[5] = 3;
    m[6] = 2;

    for(int i = 7; i <= N+1; i++) {
        int rem = i % 6;
        if(rem == 1 || rem == 5) {
            m[i] = m[i-1] + 1;
        } else if (rem == 2) {
            m[i] = min(m[i/2]+1, m[i-1]+1);
        } else if (rem == 3) {
            m[i] = min(m[i/3]+1, m[i-1]+1);
        } else if (rem == 4) {
            m[i] = min(m[i-1]+1, m[i/2]+1);
        } else if (rem == 0) {
            m[i] = min(m[i/3]+1, m[i/2]+1);
        }
    }


    cout << m[N];


}