#include <bits/stdc++.h>
using namespace std;

int n, l, a[104][104], b[104][104];
int ret = 0;

void solve(int a[104][104]) {
    for(int i = 0; i < n; i++) {
        int cnt = 1;
        int j;
        for(j = 1; j < n; j++) {
            if(a[i][j-1] == a[i][j]) cnt++;
            else if (a[i][j-1] + 1 == a[i][j] && cnt >= l) cnt = 1;
            else if (a[i][j-1] - 1 == a[i][j] && cnt >= 0) cnt = -l + 1;
            else break;
        }
        if(j == n && cnt >= 0) {
            ret++;
        }
    }
    return;
}


int main() {
    cin >> n >> l;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> a[i][j];
            b[j][i] = a[i][j];
        }
    }
    solve(a); 
    solve(b);

    cout << ret;

}