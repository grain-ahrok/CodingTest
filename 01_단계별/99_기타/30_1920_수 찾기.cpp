#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);
    
    int N, M;
    string temp;
    map<string, int> check;

    cin >> N;
    for(int i = 0; i < N; i++) {
        cin >> temp;
        check[temp] = 1;
    }

    cin >> M;
    for(int i = 0; i < M; i++) {
        cin >> temp;
        cout << check[temp] << "\n";
    }
}