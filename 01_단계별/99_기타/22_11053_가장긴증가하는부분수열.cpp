#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, Max = 0, cntM = 0, res = 0;

    int nums[1001] = {0, };
    int dp[1001] = {0, };

    cin >> N;
    for(int i = 0; i < N; i++) {
        cin >> nums[i];
    }

    for(int i = 0; i < N; i++) {
        dp[i] = 1;
        cntM = 0;
        for(int j = i-1; j >=0; j--) {
            if(nums[i] > nums[j]) {
                cntM = max(cntM, dp[j]);
            }
        }
        dp[i] += cntM;
        res = max(dp[i], res);
    }

    cout << res;
}