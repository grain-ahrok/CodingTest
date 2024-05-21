#include <bits/stdc++.h>
using namespace std;

int main() {
    
    int N, temp;
    vector<int> v;  // input 숫자 담는 곳
    vector<int> res;    // 출력 숫자 담는 곳
    stack<int> s;   // index 담는 곳

    cin >> N;

    res.resize(N+1, -1);

    for(int i = 0; i < N; i++) {
        cin >> temp;
        v.push_back(temp);
    }

    for(int pos = 0; pos < N; pos++) {
        while(s.size() && v[s.top()] < v[pos]) {
            res[s.top()] = v[pos];
            s.pop();
        }
        s.push(pos);
    }

    for(int i = 0; i < N; i++) {
        cout << res[i] << " ";
    }

}