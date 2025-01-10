#include <bits/stdc++.h>
using namespace std;

int query(int a, int b) {
    cout << "? " << a << " " << b << endl;
    cout.flush();
    int x; 
    cin >> x;
    return x;
}

void print_tree(const vector<pair<int, int>>& edges) {
    cout << "! ";
    for(const auto& edge : edges) {
        cout << edge.first << " " << edge.second << " ";
    }
    cout << endl;
    cout.flush();
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int T, N;
    cin >> T;

    while(T--) {
        cin >> N; 

        vector<pair<int, int>> v;
        set<int> s;
        s.insert(1);

        for(int i = 2; i <= N; ++i) {
            int x = query(1, i);
            v.push_back({x, i});
            s.insert(i);
        }
        print_tree(v);

    }
    return 0;
}