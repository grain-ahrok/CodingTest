#include <bits/stdc++.h>
using namespace std;



int main() {
    int N, tmp1, tmp2;
    cin >> N;
    int score[N+1], dp[N+1];
    fill_n(score, N+1, 0);
    fill_n(dp, N+1, 0);

    for(int i = 1; i < N+1; i++) {
        cin >> score[i];
    }

    dp[1] = score[1];
    dp[2] = score[1] + score[2];

    // 점화식
    // 1. 연속된 경우
    // n = n + n-1 + n-3
    // 2. 연속되지 않은 경우
    // n = n + n-2  

    for(int i = 3; i <= N; i++) {
        tmp1 = score[i] + score[i-1] + dp[i-3];
        tmp2 = score[i] + dp[i-2];
        dp[i] = max(tmp1, tmp2);
    }
    cout << dp[N];
}