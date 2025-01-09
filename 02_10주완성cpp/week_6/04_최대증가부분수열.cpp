#include <bits/stdc++.h>
using namespace std;

// 부분 수열 길이 구하기

int a[1001], N, b[1001], ret = 0;

int main() {

    cin >> N;
    for(int i = 0; i < N; i++) {
        cin >> a[i];
    }

    for(int i = 0; i < N; i++) {
        int tmp = 0;
        for(int j = i-1; j >= 0; j--) {
            if(a[j] < a[i]) {
                tmp = max(b[j], tmp);
            }
        }
        b[i] = tmp + 1;
        ret = max(ret, b[i]);
    }

    cout << ret; 
    return 0 ;
}