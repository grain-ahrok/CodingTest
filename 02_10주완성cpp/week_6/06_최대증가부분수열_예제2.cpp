#include <bits/stdc++.h>
using namespace std;

// 부분증가수열길이의 최댓값을 O(nlogn)으로 찾는 방법

int main () {

    int N, lis[1001], num, len=0;
    cin >> N;
    fill_n(lis, N, 0);

    for(int i = 0; i < N; i++) {
        cin >> num;
        auto lowerPos = lower_bound(lis, lis + len,num);
        if(*lowerPos == 0) len ++;
        *lowerPos = num;
    }

    cout << len;
    return 0;
}