#include <bits/stdc++.h>
using namespace std;

int vIdx = -1;
map<int, pair<int, int>> v;

// n >= 2
void pushV(int n) {
    int cnt0 = v[n-1].first + v[n-2].first;
    int cnt1 = v[n-1].second + v[n-2].second;
    vIdx = n;
    v[n] = {cnt0, cnt1};
}


int main() {
    cin.tie(NULL); cout.tie(NULL);
    ios::sync_with_stdio(false);

    int T, N;
    cin >> T;
    v[0] = {1, 0};
    v[1] = {0, 1};
    vIdx = 1;

    for(int i = 0; i < T; i++) {
        cin >> N;

        for(int i = vIdx+1; i <= N; i++) {
            pushV(i);
        }
        cout << v[N].first << " " << v[N].second << "\n";
    }
}