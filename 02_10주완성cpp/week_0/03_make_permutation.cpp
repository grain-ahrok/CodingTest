#include <bits/stdc++.h>
using namespace std;
vector<int> v;

void make_permutation(int n, int r, int depth) {
    if(depth == r) {
        for(int a : v) cout << a << " ";
        cout << endl;
        return;
    }

    for(int i = depth; i < n; i++) {
        swap(v[i], v[depth]);
        make_permutation(n, r, depth + 1);
        swap(v[i], v[depth]);
    }
}

int main() {
    for(int i = 1; i < 4; i++) v.push_back(i);
    make_permutation(3, 3, 0);
}