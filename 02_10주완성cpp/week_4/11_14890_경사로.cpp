#include <bits/stdc++.h>
using namespace std;

int m[101][101];
int r[101];
int N, L;

int checkCross(vector<int> v){
    fill_n(r, N, 0);

    for(int i = 1; i < N; i++) {

        // 1. 전칸에서 그냥 걸어갈 수 있는 경우
        if(v[i-1] == v[i]) continue;

        // 2. 차이가 2이상 나는 경우 
        if(abs(v[i-1]-v[i])>=2) return 0;
        
        // 3. 앞에 경사로를 두어야 하는 경우
        if(v[i-1] - v[i] == -1) {
            if(i-L < 0) return 0;
            for(int j = i-L; j < i; j++) {
                if(v[j] != v[i-1]) return 0;
                if(r[j]) return 0;
                r[j] = 1;
            }
        }
        // 4. i부터 경사로를 두어야 하는 경우
        if(v[i-1] - v[i] == 1) {
            if(i+L > N) return 0;
            for(int j = i; j < i+L; j++) {
                if(v[j] != v[i]) return 0;
                r[j] = 1;
            }
            i = i+L-1;
        }
    }
    return 1;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N >> L;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++){
            cin >> m[i][j];
        }
    }

    int res = 0;

    // 가로 행으르 돌면서 확인하기
    for(int i = 0; i < N; i++) {
        vector<int> v(begin(m[i]), begin(m[i]) + N);
        if(checkCross(v) == 1) res++;

    }

    // 세로 행으로 돌면서 확인하기
    for(int i = 0; i < N; i++) {
        vector<int> v;
        for(int j = 0; j < N; j++) {
            v.push_back(m[j][i]);
        }
        if(checkCross(v) == 1) res++;
    }

    cout << res << "\n";


}