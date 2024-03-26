#include <bits/stdc++.h>

using namespace std;

int visited[100001];
int N, K;


int main() {

    cin >> N >> K;

    visited[N] = 1;

    queue<int> q;
    q.push(N);

    while(q.size()) {
        int now = q.front();
        q.pop();

        for(int next : {now-1, now+1}) {
            if(next < 0 || next > 100000) continue;
            if(visited[next] > visited[now] + 1) {
                visited[next] = visited[now] + 1;
            }
            else if (visited[next] == 0) {
                visited[next] = visited[now] + 1;
                q.push(next);
            }
        }
        int next = now*2;
        if(next < 0 || next > 100000) continue;
        if(visited[next] > visited[now]) {
            visited[next] = visited[now];
        } else if(visited[next] == 0) {
            visited[next] = visited[now];
            q.push(next);
        }
    }
    cout << visited[K]-1 << "\n";


}