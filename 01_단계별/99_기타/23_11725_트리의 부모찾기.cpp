#include <bits/stdc++.h>
using namespace std;

int visited[100001] = {0, };
vector<int> ns[100001];

void recur(int parent) {
    if(ns[parent].size() == 0) return;
    for(int node : ns[parent]) {
        if(visited[node]) continue;
        visited[node] = parent;
        recur(node);
    }
}

int main () {
    int N;
    cin >> N;
    
    int tmp1, tmp2;
    for(int i=0; i< N-1; i++) {
        cin >> tmp1 >> tmp2;
        ns[tmp1].push_back(tmp2);
        ns[tmp2].push_back(tmp1);
    }

    visited[1] = 1;
    recur(1);

    for(int i = 2; i <= N; i++) {
        cout << visited[i] << "\n";
    }

}