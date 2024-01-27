#include <bits/stdc++.h>
using namespace std;

string s;
bool isYes = true;

int main() {

    cin.tie(NULL); cout.tie(NULL);
    
    cin >> s;

    if( s[0] < 'A' || s[0] > 'Z') isYes = false;
    for(int i = 1; i < s.length() && isYes; i++) {
        if(s[i]<'a' || s[i]>'z')  isYes = false;
    }

    cout << (isYes ? "Yes" : "No");

    return 0;
}