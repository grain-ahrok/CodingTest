#include <bits/stdc++.h>
using namespace std;



int main() {
    int H, W, cnt = 0;
    bool miss;
    string str;
    cin >> H >> W;

    for(int h = 0; h < H; h++) {
        cin >> str;
        for(int w = 0; w < W; w++) {
            cnt = 0;
            miss = true;
            for(int i = w; i >=0; i--) {
                if(str[i] == 'c'){
                    miss = false;
                    break;
                } 
                else cnt++;
            }
            if(miss) cout << -1 << " ";
            else cout << cnt << " ";
        }
        cout << endl;
    }
}

