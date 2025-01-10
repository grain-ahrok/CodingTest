#include <bits/stdc++.h>
using namespace std;

int main () {

    int T, N;
    cin >> T;

    while(T--) {

        map<int, int> m;
        cin >> N;
        // M : 숫자의 최대 갯수.
        int M = 0, tmp, ret = 0;

        for(int i = 0; i < N; i++) {
            cin >> tmp;
            if(m.find(tmp) != m.end()) {
                m[tmp]++;
            } else {
                m.insert({tmp, 1});
            }
            M = max(m[tmp], M);
        }

        // 중복되는 수 갯수가 전체 배열 갯수 보다 작을 때만 실행
        while(M < N) {
            ret ++; // 배열 복제
            if(N-2*M >= 0) {
                ret += M;
                M = 2*M;
            } else if(N - 2*M < 0) {
                ret += N-M;
                M = N;
            }
        }

        cout << ret << "\n";


    }
    return 0;
}