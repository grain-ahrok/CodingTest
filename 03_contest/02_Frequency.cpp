#include <bits/stdc++.h>
using namespace std;

int alpa[26] = {0,};
int idx = 0;
char chr = 'a';
string str;

int main() {

    int max = 0;

    cin.tie(NULL); cout.tie(NULL);
    cin >> str;

    for(int i = 0; i < str.length(); i++) {
        idx = (int)(str[i]-'a');
        alpa[idx]++;
    }

    for(int i = 0; i < 26; i++) {
        if(alpa[i] > max) {
            max = alpa[i];
            chr = (char)('a' + i);
        }
    }




    cout << chr;


}