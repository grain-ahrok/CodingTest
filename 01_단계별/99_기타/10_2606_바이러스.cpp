#include <bits/stdc++.h>
using namespace std;

int main() {
    bool visited[101];
    int res = 0;
    vector<int> v[101];
    int cm_cnt, cnt, temp1, temp2;
    cin >> cm_cnt >> cnt;

    for(int i = 0; i < cnt; i++) {
        cin >> temp1 >> temp2;
        v[temp1].push_back(temp2);
        v[temp2].push_back(temp1);
    }

    // 1번이 바이러스 걸렸을때 바이러스가 퍼지는 컴퓨터 수.
    visited[1] = 1;
    queue<int> q;
    q.push(1);

    while(q.size()) {
        int cur = q.front();
        q.pop();

        for(int i = 0; i < v[cur].size(); i++) {
            if(visited[v[cur][i]]) continue;
            q.push(v[cur][i]);
            res++;
            visited[v[cur][i]] = 1;
        }
    }

    cout << res;

}