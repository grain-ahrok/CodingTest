#include <bits/stdc++.h>
using namespace std;
vector<int> v;

void make_permutation(int n, int r, int depth) {
    if(r == depth) {
        for(int k : v) cout << k << " ";
        cout << endl;
        return;
    }
    for(int i = depth; i < n; i++) {
        swap(v[i], v[depth]);
        make_permutation(n, r, depth + 1);
        swap(v[depth], v[i]);
    }
}

int main() {
    for(int i = 1; i < 5; i++) v.push_back(i);
    make_permutation(4, 2, 0);
}