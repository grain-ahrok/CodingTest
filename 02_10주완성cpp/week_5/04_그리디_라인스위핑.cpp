#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, from, to, ret = 0;

int main () {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 

    cin >> n;
    vector<pair<int, int>> v;

    for(int i = 0; i < n; i++) {
        cin >> from >> to;
        v.push_back({from, to});
    }
    
    sort(v.begin(), v.end());

    from = v[0].first;
    to = v[0].second;

    for(int i = 1; i < n; i++) {
        if(v[i].first <= to && to < v[i].second) {
            to = v[i].second;
        } else {
            ret += to-from;
            from = v[i].first;
            to = v[i].second;
        }
    }
    ret += to-from;

    cout << ret;
    return 0;
}