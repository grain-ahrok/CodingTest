#include <bits/stdc++.h>

using namespace std;
int N, K;
int visited[2][500001];

int main() {
    cin >> N >> K;

    queue<int> q;
    q.push(N);
    visited[0][N] = 1;
    int prev = 1;
    long long int cnt;

    while(q.size()) {

         if(visited[prev % 2 ^1][K] == true) {
            cout << prev - 1;
            return 0;
        }
        cnt = q.size();

        for(long long int i = 0; i < cnt; i++) {

            int now = q.front();
            q.pop();

            for(int next : {now-1, now+1, now*2}) {
                if(next < 0 || next > 500000 || visited[prev % 2][next] ) continue;
                visited[prev % 2][next] = true;
                q.push(next);
            }
        }

        K+= prev;
        prev++;
        
        if(K > 500000) {
            cout << -1;
            break;
        }

    }

}