#include <bits/stdc++.h>
using namespace std;

int main () {
    int S = 18; // 10010
    int idx = 1;
    S &= ~(1 << idx);
    cout << S ;
}