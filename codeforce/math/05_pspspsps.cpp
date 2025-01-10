#include <bits/stdc++.h>
using namespace std;

int main () {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int T;
    cin >> T;

    while(T--) {
        int N;
        string S;
        cin >> N >> S;

        bool ret = true;
        bool isPExist = false;
        for(int i = 0; i < N; i++) {
            if(S[i] == 'p') isPExist = true;
            if(S[i] == 's' && isPExist) {
                ret = false; 
                break;
            }
        }

        if (ret == false) {
            cout << "NO\n";
            continue;
        }

        bool isSExist = false;
        for(int i = 1; i < N-1; i++) {
            if(S[i] == 's') isSExist = true;
            if(isSExist && S[i] == 'p') {
                ret = false;
                break;
            }
        }

        if(ret) cout << "YES\n";
        else cout << "NO\n";

    }
    return 0;

}