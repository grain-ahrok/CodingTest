#include <bits/stdc++.h>
using namespace std;

int main() {
    int N; 
    cin >> N;
    int a[1001];

    a[1] = 1;
    for(int i = 2; i <= N; i++) {
        a[i] = int(2*a[i-1] + pow(-1, i)) % 10007;
    }

    cout << a[N];

}