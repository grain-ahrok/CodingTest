#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    int x, y;
    vector<pair<int, int>> v;

    cin >> N;
    for(int i = 0; i < N; i++) {
        cin >> x >> y;
        v.push_back({x,y});
    }

    sort(v.begin(), v.end());

    for(auto item : v) {
        cout << item.first << " " << item.second << "\n";
    }

}