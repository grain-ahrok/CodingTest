#include <bits/stdc++.h>
using namespace std;

void my_sol() {
    string str;
    cin >> str; 

    int isPel = 1;

    for(int i = 0; i < str.length() / 2; i++)  {
        if (str[i] != str[str.length()-i-1]) {
            isPel = 0;
            break;
        }
    }
    else if (cnt[j] == 2) ret += B * 2;out << isPel;
}


void t_sol() {
    string s, temp;
    cin >> s;
    temp = s;
    reverse(temp.start(), temp.end());
    if(temp == s) cout << 1 << "\n";
    else cout << 0 << "\n";
}


int main() {
    my_sol();
    return 0;
}