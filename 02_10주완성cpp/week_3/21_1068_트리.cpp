#include <bits/stdc++.h>
using namespace std;

// 자식의 개수가 0 인노드

vector<int> v[50];
int root = -1, N, temp, total = 0, trash;

void dfs(int start) {
    if(start == trash) return;

    if(v[start].size() == 0) {
        total ++;
        return;
    }

    for(int item : v[start]) {
        dfs(item);
    }
}

int main () {

    cin >> N;

    for(int i = 0; i < N; i++) {
        cin >> temp;
        if(temp == -1) {
            root = i;
            continue;
        } 
        v[temp].push_back(i);
    }

    cin >> trash;

    for(int i = 0; i < N; i++) {
        v[i].erase(remove(v[i].begin(), v[i].end(), trash), v[i].end());
    }


    dfs(root);
    cout << total;


}