#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    // 0 -> 모두 0인 경우
    // 1 -> 양수가 포함 되어 있지만, 0 양 0 | 0 양 | 양 0 의 형태인 경우
    // 2 -> 양수 포함, 양 0 양 형태 포함

    int T;
    cin >> T;
    while(T--) {
        int N, tmp; 
        cin >> N; 

        vector<int> v;
        bool onlyZeoro = true;
        for(int i = 0; i < N; i++) {
            cin >> tmp;
            v.push_back(tmp);
            if(tmp > 0) onlyZeoro = false;
        }


        // 0 만 있는 경우
        if(onlyZeoro) {
            cout << 0 << "\n";
            continue;
        }

        // 양 0 양 형태가 존재하는지 체크
        bool P0P = false;

        bool isPosExist = false;
        bool isZeroExist = false;
        for(int i = 0; i < N; i++) {
            if(isPosExist && isZeroExist && v[i]>0) {
                P0P = true;
                break;
            }

            if(v[i] > 0) {
                isPosExist = true;
                isZeroExist = false;
            } else if(v[i] == 0){
                isZeroExist = true;
            }
        }

        if(P0P) cout << 2 << "\n";
        else cout << 1 << "\n";
    }
}