#include <bits/stdc++.h>

using namespace std;

int comp(pair<int, int> a, pair<int, int> b){
    if(a.first == b.first) {
        return a.second < b.second;
    }
    return a.first > b.first;
}

int main() {

    int N, n, idx, tmp;
    int lIdx, cIdx, cnt;
    cin >> N;
    int pa[101][2] = {{0,},};
    

    for(; N > 0; N--) {
        
        lIdx = 0;
        cIdx = 0;
        cnt = 0;
        cin >> n >> idx;
        
        
        for(int i = 0; i < n; i++) {
            cin >> pa[i][0];
        }

        for(int j = 9; j > pa[idx][0]; j--) {
            for(int i = 0; i < n; i++) {
                tmp = (lIdx + i) % n;

                if(pa[tmp][0] == j) {
                    cnt++;
                    pa[tmp][1] = 1;
                    cIdx = tmp;
                }

            }
            lIdx = cIdx;
        }

        for(int i = 0; i < n; i++) {
            tmp = (lIdx + i) % n;
            if(pa[tmp][0] != pa[idx][0]) continue;
            
            if(tmp == idx) {
                cnt ++; 
                break;
            } else {
                cnt ++;
            }
        }

        cout << cnt << "\n";

    }

}
