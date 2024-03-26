#include <bits/stdc++.h>

using namespace std;

int visited[100001];
int cnt[100001];
int rollback[100001];
int min_cnt;
int N, K;
vector<int> ret;


void dfs(int cur) {
    ret.push_back(cur);
    if(min_cnt == 1) return;
    

    // +1 , -1 확인 후 있으면 
    for(int next : {cur-1, cur+1}) {
        if(next < 0 || next > 100000) continue;
        if(visited[next] == min_cnt -1) {
            min_cnt--;
            dfs(next);
            return;
        }
    }

    int next = cur / 2;
    min_cnt--;
    dfs(next);

}




int main() {

    cin >> N >> K;

    visited[N] = 1;
    cnt[N] = 1;

    queue<int> q;
    q.push(N);

    while(q.size()) {
        int now = q.front();
        q.pop();

        for(int next : {now-1, now+1, now*2}) {
            if(next < 0 || next > 100000) continue;
            if(visited[next] == visited[now] + 1) {
                cnt[next] += cnt[now];
            } else if (visited[next] == 0) {
                visited[next] = visited[now] + 1;
                cnt[next] = cnt[now];
                q.push(next);
            }
        }
    }

    min_cnt = visited[K];
    cout << visited[K]-1 << "\n";


    dfs(K);
    for(int i = ret.size()-1; i >= 0; i --) cout << ret[i] << " ";
}