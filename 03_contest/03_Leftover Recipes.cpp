#include <bits/stdc++.h>
using namespace std;

// https://atcoder.jp/posts/745

vector<pair<int, int>> cnt;

int main() {
    int Q[10] = {0, };
    int A[10] = {0, };
    int B[10] = {0, };
    int max = 0;

    int N;
    cin >> N;

    for(int i = 0; i < N; i++) cin >> Q[i];
    for(int i = 0; i < N; i++) cin >> A[i];
    for(int i = 0; i < N; i++) cin >> B[i];

    int temp1 = A[0] == 0 ? Q[0] : Q[0] / A[0];
    int temp2 = B[0] == 0 ? Q[0] : Q[0] / B[0];
    for(int i = 0; i <= temp1; i++) {
        for(int j = 0; j <= temp2; j++){
            if(A[0]*i + B[0]*j == Q[0]) {
                cnt.push_back({i, j});
            }
        }
    }

    for(auto it : cnt) {
        bool check = true;

        if(it.first + it.second < max ) continue;

        for(int i = 1; i < N && check; i++){
            if(A[i]*it.first + B[i]*it.second != Q[i]) {
                check = false;
                cnt.pop_back();
            }
        }
        if(check && it.first + it.second > max ) {
            max = it.first + it.second;
        }
    }




    cout << max;
    return 0;
}