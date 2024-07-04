#include <bits/stdc++.h>
using namespace std;

int main() {
    int N; 
    cin >> N; 
    int temp;
    vector<int> v;
    for(int i = 0 ; i < N; i++ ){
        cin >> temp;
        v.push_back(temp);
    }
    sort(v.begin(), v.end());
    int res = 0;
    for(int i = 0; i < N; i++) {
        res += v[i] * (N-i);
    }
    cout << res;
} 