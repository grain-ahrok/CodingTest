#include <bits/stdc++.h>
using namespace std;

int cnt = 0;

void solve(int N) {
    cnt++;
    if(N == 0) return;
    for(int i = 0; i < 3; i++) {
        solve(N-1);
    }
    return;
}


int main() {
    int N;
    cin >> N ;
    solve(N);
    return 0;
}
