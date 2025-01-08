#include <bits/stdc++.h>
using namespace std;

int n, tmp, x, ret = 0;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int> v;

    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> tmp;
        v.push_back(tmp);
    }
    cin >> x;
    sort(v.begin(), v.end());
    

    int i = 0; 
    int j = n-1;
    while(i < j) {
        if (v[i] + v[j] == x) {
            ret++;
            j--;
        } else if(v[i] + v[j] < x) {
            i++;
        } else if(v[i] + v[j] > x) {
            j--;
        }
    }
    
    cout << ret;
    return 0;



}