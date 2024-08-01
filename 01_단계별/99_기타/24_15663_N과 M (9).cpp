#include <bits/stdc++.h>
using namespace std;

int M, N, temp;

vector<int> v;
vector<vector<int>> res;

int main() {
    
    cin >> M >> N;
    for(int i = 0; i < M; i++) {
        cin >> temp;
        v.push_back(temp);
    }

    sort(v.begin(), v.end());
    vector<int> newV;
    do {
        newV.clear();
        for(int i = 0; i < N; i++) {
            newV.push_back(v[i]);
        }
        res.push_back(newV);
        
    } while(next_permutation(v.begin(), v.end()));


    sort(res.begin(),res.end());
    res.resize(unique(res.begin(), res.end()) - res.begin());

    for(auto ans : res) {
        for(int i : ans) {
            cout << i << " ";
        }
        cout << "\n";
    }
}   

