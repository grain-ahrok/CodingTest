#include <bits/stdc++.h>
using namespace std;

vector<int> v;
int rmin =  5;

void recur(int num, int prei) {

    if(v.size() >= 4) {
        return;
    }
    int rn = pow(num, 0.5);
    for(int i = min(rn, prei); i > 0; i--) {
        num = num - pow(i, 2);

        if(num == 0) {
            rmin = min(rmin, (int)v.size()+1);
            // for(int j = 0; j < v.size(); j++) {
            //     cout << v[j] << " ";
            // }
            // cout << i << "\n";
            break;

        } else if(num < 0) {
            break;

        } else {
            v.push_back(i);
            recur(num, i);
            v.pop_back();
            num = num + pow(i, 2);
        }
    }
}

int main() {

    int N;
    cin >> N;
    recur(N, N);

    cout << rmin;
}
