#include <bits/stdc++.h>
using namespace std;

// 최하위 켜쳐있는 비트 : 10010 에서 오른쪽에서 두번째 녀석.
// -S = ~S + 1
int main() {
    int S = 18;
    int idx = S & -S;
    cout << idx;
}