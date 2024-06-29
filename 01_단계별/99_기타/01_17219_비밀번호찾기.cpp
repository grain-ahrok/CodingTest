#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int N, M;
    map<string, string> m;

    cin >> N >> M;
    string temp1, temp2;
    for(int i = 0; i < N; i++) {
        cin >> temp1 >> temp2;
        m[temp1] = temp2;
    }

    for(int i = 0; i < M; i++) {
        cin >> temp1;
        cout << m[temp1] << "\n";
    }


}
