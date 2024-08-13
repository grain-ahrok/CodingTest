#include <bits/stdc++.h>
using namespace std;

int main() {
    
    
    int N;
    int k;
    vector<int> v;


    cin >> N;
    cin >> k;
    
    cout << "여기 괜춘";
    for(int i = 1; i<= N; i++) {
        v.push_back(i);
    }
    

    int idx = k;
    while(v.size()) {
        cout << v[idx] << ", ";
        v.erase(v.begin()+idx);
        idx = idx+(k-1) % v.size();
    }
}