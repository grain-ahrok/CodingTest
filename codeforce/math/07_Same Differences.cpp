#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while(T--) {
        int N;
        cin >> N;

        int tmp;
        map<int, ll> m;

        for(int i = 0; i < N; i++) {
            cin >> tmp;
            if(m.find(tmp-i) != m.end()) {
                m[tmp-i]++;
            } else {
                m.insert({tmp-i, 1});
            }
        }

        ll ret = 0;
        for(auto item : m) {
            // cout << item.first << " : " << item.second << "\n";
            ret += item.second * (item.second - 1) / 2;
        }
        cout << ret << "\n";

    }
    return 0;
}