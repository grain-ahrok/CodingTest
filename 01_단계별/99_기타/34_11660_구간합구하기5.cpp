#include <bits/stdc++.h>
using namespace std;

int m[1025][1025];
int N, M;

int main() {
    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin >> N >> M;
    int sum, tmp;
    for(int i = 1; i <= N; i++) {
        sum = 0;
        for(int j = 1; j <= N; j++) {
            cin >> tmp;
            m[i][j] = sum + tmp;
            sum = m[i][j];
        }
    }

    int x1, y1, x2, y2, res;
    for(int i = 0; i < M; i++) {
        res = 0;
        cin >> x1 >> y1 >> x2 >> y2;
        for(int k = x1; k <= x2; k++) {
            res += m[k][y2] - m[k][y1-1];
        }
        cout << res << "\n";
    }

}