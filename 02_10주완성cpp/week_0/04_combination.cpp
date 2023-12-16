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


// 재귀함수로
void combine2(int start, vector<int> b) {
    if(b.size() == k) {
        for(int l : b) cout << l << " ";
        cout << endl;
        return;
    }
    for(int i = start + 1; i < n; i++) {
        b.push_back(i);
        combine2(i, b);
        b.pop_back();
    }
    return;
}


int main() {
    for(int i = 1; i < n+1; i++) b.push_back(i);
    combine1();
    combine2(-1, b);
}

