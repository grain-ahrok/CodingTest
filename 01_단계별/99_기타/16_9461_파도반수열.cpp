#include <bits/stdc++.h>
using namespace std;

int main() {
    int T;
    cin >> T;
    long long a[101];
    a[1] = 1;
    a[2] = 1;
    a[3] = 1;
    a[4] = 2;
    a[5] = 2;

    for(int i = 6; i <= 100; i++) {
        a[i] = a[i-1] + a[i-5];
    }


    while(T) {
        int idx;
        cin >> idx;
        cout << a[idx] << "\n";
        T--;
    }
}