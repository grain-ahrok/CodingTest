#include <bits/stdc++.h>
using namespace std;

int main() {
    int T, cnt, res=1;
    string tmp1, tmp2;

    cin >> T;
    for(; T; T--) {

        map<string, int> m;
        cin >> cnt;
        res = 1;
        for(; cnt; cnt--) {
            cin >> tmp1 >> tmp2;
            if(m.find(tmp2) != m.end()) {   // 존재하면 
                m[tmp2] = m[tmp2]+1;
            }else {
                m[tmp2] = 1;
            }
        }

        for (const auto& [key, value] : m) {
            res *= (value+1);
        }
        cout << res-1 << "\n";

    }
    
}

