#include <bits/stdc++.h>
using namespace std;

int N, mmap[20];
int Tmin = 0;
// H : 앞, T : 뒤
int main() {
    cin >> N;
    Tmin = N * N;
    string temp;
    for(int i = 0; i < N; i++) {
        cin >> temp;
        int tempi = 0;
        for(int j = 0; j < N; j++) {
            if(temp[j] == 'H') tempi ^= (1 << (N-j-1));
            mmap[i] = tempi;
        }
    }


    int Hcnt = 0, Tcnt = 0, total_cnt = 0;
    for(int j = 0; j < pow(2,N) / 2; j++) {
        total_cnt = 0;
        // j 숫자중 1인 부분 
        // 세로로 뒤집기
        for(int i = 0; i < N; i++) {
            mmap[i] ^= j;
        }

        // 행 돌면서 H, T 숫자중 작은 거 더하기
        for(int a = 0; a < N; a++) {
            Hcnt = 0, Tcnt = 0;
            for(int b = N-1; b >= 0; b--) {
                if((mmap[a]>> b) & 1) Hcnt++;
                else Tcnt++;
            }
            total_cnt += min(Hcnt, Tcnt);
        }

        Tmin = min(Tmin, total_cnt);

        // 원복
        for(int i = 0; i < N; i++) {
            mmap[i] ^= j;
        }
    }

    cout << Tmin;
}


