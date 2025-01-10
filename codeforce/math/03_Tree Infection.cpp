#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T;
    cin >> T;

    while(T--) {
        int N, tmp;
        cin >> N;

        map<int, int> m;
        for(int i = 0; i < N-1; i++){
            cin >> tmp;
            if(m.find(tmp) != m.end()) {
                m[tmp]++;
            }else {
                m.insert({tmp, 1});
            }
        }

        int cnt = 1;
        vector<int> v;
        v.push_back(1);  // 루트 추가

        for(auto item : m) {
            v.push_back(item.second);
            cnt ++;
        }
        sort(v.begin(), v.end(), greater<int>());

        priority_queue<int> pq;
        for(int i = 0; i < cnt; i++){
            pq.push(i+v[i]);
        }

        for(; cnt < pq.top(); cnt++) {
            pq.push(pq.top()-1);
            pq.pop();
        }

        cout << cnt << "\n";
    }

    return 0;
    
}