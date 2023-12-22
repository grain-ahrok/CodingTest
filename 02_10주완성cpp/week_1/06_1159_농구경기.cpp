#include <bits/stdc++.h>
using namespace std;

int main() {
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