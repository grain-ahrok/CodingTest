#include <bits/stdc++.h>
using namespace std;

// map을 사용해서 중복을 제거하는 방법
void uniaue1() {
    map<int, int> mp;
    vector<int> v = {1, 1, 2, 2, 3, 3};
    for(int i : v) {
        if(mp[i]) {
            continue;
        } else {
            mp[i] = 1;  
        }
    }
    vector<int> ret;
    for(auto it : mp) {
        ret.push_back(it.first);
    }   
    for(int a : ret) cout << a << " ";
}

void unique2() {
    vector<int> v = {2, 2, 1, 1, 2, 2, 3, 5, 7, 8, 9, 7, 8, 9};
    sort(v.begin(), v.end());
    for(int i : v) cout << i << " ";
    cout << endl;

    v.erase(unique(v.begin(), v.end()), v.end()); 
    for(int i : v) cout << i << " ";
    cout << endl;
}


int main() {
    unique2();
}