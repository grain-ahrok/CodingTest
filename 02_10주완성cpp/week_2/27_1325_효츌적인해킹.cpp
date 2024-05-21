#include <bits/stdc++.h>
using namespace std;


int main() {

    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

    vector<int> mmap[10001];
    vector<bool> visited;
    vector<int> res;

    int N, M;
    int temp1, temp2;
    cin >> N >> M;

    for(int i = 0; i < M; i++) {
        cin >> temp1 >> temp2;
        mmap[temp2].push_back(temp1);
    }

    visited.resize(N+1, 0);

    int mmax = 1;
    int start;
    int cnt;
    queue<int> v;

    for(int i = 1; i <= N; i++) {
        cnt = 1;
        visited[i] = 1;

        for(int item : mmap[i]) {
            if(visited[item]) continue;
            v.push(item);
            visited[item] = 1;
            cnt++;
        }

        while(v.size()) {
            start = v.front();
            v.pop();
            for(int item : mmap[start]) {
                if(visited[item]) continue;
                v.push(item);
                visited[item] = 1;
                cnt++;
            }
        }

        if(mmax < cnt) {
            res.clear();
            res.push_back(i);
            mmax = cnt;
        } else if(mmax == cnt) {
            res.push_back(i);
        }

        

        fill(visited.begin(), visited.end(), 0);
    }

    sort(res.begin(), res.end());
    for(int item : res) {
        cout << item << " ";
    }
    
}