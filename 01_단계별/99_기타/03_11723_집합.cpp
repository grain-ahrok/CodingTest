#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    int N; 
    cin >> N;

    string S;
    int I, v[21];

    /**
     *  add x: S에 x를 추가한다. (1 ≤ x ≤ 20) S에 x가 이미 있는 경우에는 연산을 무시한다.
        remove x: S에서 x를 제거한다. (1 ≤ x ≤ 20) S에 x가 없는 경우에는 연산을 무시한다.
        check x: S에 x가 있으면 1을, 없으면 0을 출력한다. (1 ≤ x ≤ 20)
        toggle x: S에 x가 있으면 x를 제거하고, 없으면 x를 추가한다. (1 ≤ x ≤ 20)
        all: S를 {1, 2, ..., 20} 으로 바꾼다.
        empty: S를 공집합으로 바꾼다.
    */
    for(int i = 0; i < 21; i++) {
        v[i] = 0;
    }
    fill_n(v, 21, 0);

    for(int i = 0; i < N; i++) {
        cin >> S;
        if(S == "add") {
            cin >> I;
            v[I] = 1;

        } else if(S == "remove") {
            cin >> I;
            v[I] = 0;

        } else if(S == "check") {
            cin >> I;
            cout << v[I] << "\n";

        } else if(S == "toggle") {
            cin >> I;
            v[I] ^= 1;

        } else if(S == "all") {
            fill_n(v, 21, 1);
        } else if(S == "empty") {
            fill_n(v, 21, 0);
        }

    }
}