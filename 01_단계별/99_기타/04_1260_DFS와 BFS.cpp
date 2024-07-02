#include <bits/stdc++.h>

using namespace std;

bool m[1001][1001] = {{0,},};
bool visited[1001] = {0,};




int main () {

    int N, M, V;
    cin >> N >> M >> V;

    int t1, t2;
    for(int i = 0; i < M; i++) {
        cin >> t1 >> t2;
        m[t1][t2] = 1;
        m[t2][t1] = 1;
    }


    // DFS 부터!
    stack<int> s;
    s.push(V);
    while(s.size()) {
        int cur = s.top();
        s.pop();
        if(visited[cur]) continue;
        visited[cur] = 1;
        cout << cur << " ";
        for(int i = N; i >= 1; i-- ) {
            if(visited[i] || m[cur][i] == 0 ) continue;
            s.push(i);
        }
    }

    cout << "\n";
    fill_n(visited, N+1, 0);

    // BFS 부터!
    queue<int> q;
    q.push(V);
    visited[V] = 1;
    cout << V << " ";
    while(q.size()) {
        int cur = q.front();
        q.pop();
        for(int i = 1; i <= N; i++) {
            if(visited[i] || m[cur][i] == 0) continue;
            q.push(i);
            visited[i] = 1;
            cout << i << " ";
        }
    }


}