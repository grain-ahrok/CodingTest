#include <bits/stdc++.h>
using namespace std;

void my_sol() {
    int alpa[26] = {0,};
    int cnt;
    cin >> cnt;

    bool canCompet = false;
    string name;
    for(int i = 0; i < cnt; i++) {
        cin >> name;
        alpa[name[0]-'a']++;
    }

    for(int i = 0; i < 26; i++) {
        if(alpa[i] >= 5) {
            canCompet = true;
            cout << (char)(i+'a');
        }
    }
    if(canCompet == false) {
        cout << "PREDAJA";
    }
}

void t_sol(){
    int n, cnt[26];
    string s, ret;

    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> s;
        cnt[s[0] - 'a']++;
    }
    for(int i = 0; i < 26; i++) if(cnt[i] >= 5) ret += (i+'a');
    if(ret.size()) cout << ret;
    else cout << "PREDAJA";

}

int main() {

}