#include <bits/stdc++.h>
using namespace std;

vector<int> a[10];
bool visited[10];

void go(int from) {
    visited[from] = 1;
    cout << from << endl;

    for(int to : a[from]) {
        if(visited[to]) continue;
        go(to);
    }
}


int main() {

    a[1].push_back(2);
    a[1].push_back(3);
    a[2].push_back(1);

    a[3].push_back(1);
    a[3].push_back(4);  
    a[4].push_back(3);

    for(int i = 0; i < 10; i++) {
        if(visited[i]) continue;
        if(a[i].empty() == false) {
            go(i);
        }
    }
}