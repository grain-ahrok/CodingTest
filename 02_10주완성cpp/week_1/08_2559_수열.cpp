#include <bits/stdc++.h>
using namespace std;

int main() {

    int N, K;
    cin >> N >> K;
    int nums[N];

    for(int i = 0; i < N; i++) {
        cin >> nums[i];
    }

    int max = 0; 
    for(int i = 0; i < K; i++) {
        max += nums[i];
    }

    int temp = max;
    for(int i = 0; i < N-K; i++) {
        temp = temp - nums[i] + nums[i+K];
        if(temp > max) {
            max = temp;
        }
    }

    cout << max;
}