#include <bits/stdc++.h>
using namespace std;

int N, M, temp;
vector<int> v;

void combi(int start, vector<int> newV) {
    if(newV.size() == M) {
        for(auto i : newV) cout << i << " ";
        cout << "\n";
        return;
    }
    
    for(int i = start; i < v.size(); i++) {
        newV.push_back(v[i]);
        combi(i, newV);
        newV.pop_back();
    }

}

int main() {
    
    cin >> N >> M;
    for(int i = 0; i < N; i++) {
        cin >> temp;
        v.push_back(temp);
    }

    // 받은 숫자 중 중복된 수 제거.
    sort(v.begin(), v.end());
    v.resize(unique(v.begin(), v.end()) - v.begin());

    vector<int> newV;
    combi(0, newV);

}   

