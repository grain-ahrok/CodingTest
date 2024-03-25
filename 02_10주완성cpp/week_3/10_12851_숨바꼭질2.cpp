#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int su, dd;
int visited[100001]; // 경로를 나타냄.
long long cnt[100001];

void bfs() {
    queue<int> q;
    q.push(su);

    while(!q.empty()) {
        int cur = q.front();
        q.pop();

        for(int next : {cur-1, cur+1, cur*2}) {

            /**
             * 첫번째 경우 -> 쌤풀
            */
            // if(0 <= next && next <= 100000) {
            //     if(!visited[next]) { // 방문한 적이 없는 경우
            //         visited[next] = visited[cur] + 1;
            //         cnt[next] += cnt[cur];
            //         q.push(next);
            //     } else if(visited[next] ==  visited[cur] + 1) {
            //         cnt[next] += cnt[cur];
            //     }
            // }


            if(next < 0 || next > 100000) continue;

            if(visited[next]) { // 방문한 경험이 있는 경우
                if(visited[next] < visited[cur] + 1) {  // 기존 경로가 더 빠른 경우
                    continue;
                } else if (visited[next] == visited[cur] + 1) { // 기존 경로와 같은 경우
                    cnt[next] += cnt[cur];
                } else {    // 기존경로가 더 느린경우. // visited 가 순서대로 진행되므로 이곳에 들어오지 않는다.
                    visited[next] = visited[cur] + 1;
                    cnt[next] = cnt[cur];
                }
            } else { // 방문한 경험이 없는 경우.
                visited[next] = visited[cur] + 1;
                cnt[next] = cnt[cur];
                q.push(next);
            }
        }
    }
}

int main () {
    cin >> su >> dd;

    visited[su] = 1;
    cnt[su] = 1;
    bfs();

    cout << visited[dd] -1 << "\n";
    cout << cnt[dd];

}