#include <bits/stdc++.h>
using namespace std;

vector<int> b;
int n = 5;
int k = 3;

// 중첩 for 문으로
void combine1() {
    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            for(int l = j + 1; l < n; l++) {
                // index로
                cout << i << " : " << j << " : " << l << endl;
            }
        }
    }
}

void combine2(int start, vector<int> v) {
    if(v.size() == k) {
        for (int a : v) cout << a << " ";
        cout << endl;
        return;
    }
    for(int i = start + 1; i < n; i++) {
        v.push_back(i);
        combine2(i, v);
        v.pop_back();
    }
}


int main() {
    vector<int> v;
    // for(int i = 1; i < n+1; i++) v.push_back(i);
    // combine1();
    combine2(-1, v);
}

