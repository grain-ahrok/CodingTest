#include <bits/stdc++.h>
using namespace std; 

int main () {
    int N, tmp;
    vector<int> v;
    int sum = 0;

    cin >> N;
    if(N == 0) {
        cout << "0";
        return 0;
    }

    for(int i = 1; i <= N; i++) {
        cin >> tmp;
        v.push_back(tmp);
        sum += tmp;
    }

    sort(v.begin(), v.end());

    int rmN = (int)(round(N*0.15));
    int total = 0; 

    for(int i = 0; i < rmN; i++) {
        total += v[i];
        total += v[N-i-1];
    }

    sum -= total;
    cout << round((double)sum / (N-2*rmN));


}