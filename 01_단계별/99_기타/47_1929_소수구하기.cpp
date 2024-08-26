#include <bits/stdc++.h>
using namespace std;

void check() {

}

int main() {
    int N, M;
    cin >> N >> M;
    bool isPrime = 1;
    for(int i = N; i <= M; i++) {
        if(N == 1) continue;
        if(N == 2) {
            cout << N << "\n";
            continue;
        }
        isPrime = 1;
        for(int j = 2; j < pow(i, 0.5 + 1); j++) {
            if(i % j == 0) {
                isPrime = 0;
                break;
            }
        }
        if(isPrime == 1) {
            cout << i << "\n";
        }
    }
}