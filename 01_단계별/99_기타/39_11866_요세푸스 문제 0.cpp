#include <bits/stdc++.h>
using namespace std;

int main() {
    
    
    int N;
    int k;
    vector<int> v;


    cin >> N;
    cin >> k;
    
    for(int i = 1; i<= N; i++) {
        v.push_back(i);
    }
    

    int idx = k-1;
    cout << "<";
    while(v.size()>1){
        cout << v[idx] << ", ";
        v.erase(v.begin()+idx);
        idx = (idx+(k-1)) % v.size();
    }

    cout << v[idx] << ">";
        


}