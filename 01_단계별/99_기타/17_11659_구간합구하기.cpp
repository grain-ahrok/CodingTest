#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(NULL); cout.tie(NULL);
    ios::sync_with_stdio(false);

    int N, M, ns[100001];
    cin >> N >> M;

    ns[0] = 0;
    int temp;
    for(int i = 1; i <= N; i++) {
        cin >> temp;
        ns[i] = temp + ns[i-1];
    }
    
    int tmp1, tmp2;
    for(int i = 0; i < M; i++) {
        cin >> tmp1 >> tmp2;
        cout << ns[tmp2] - ns[tmp1-1] << "\n";
    }



}