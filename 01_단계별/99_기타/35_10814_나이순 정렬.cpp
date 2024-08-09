#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<string> v[201];

    int N, n, mN=0;
    string s;
    cin >> N;
    for(int i = 0; i < N; i++) {
        cin >> n >> s;
        v[n].push_back(s);
        mN = max(n, mN);
    }

    for(int i = 1; i <= mN; i++) {
        for(auto item : v[i]){
            cout << i << " " << item << "\n";
        }
    }   
}