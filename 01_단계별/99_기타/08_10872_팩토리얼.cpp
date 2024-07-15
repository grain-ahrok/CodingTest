#include <bits/stdc++.h>
using namespace std;

int fac(int K) {
    if( K == 1 || K == 0) {
        return 1;
    }
    return K * fac(K-1);
}

int main() {
    int temp;
    cin >> temp;
    cout << fac(temp);
}