#include <bits/stdc++.h>
using namespace std;

int main() {
    string str;
    cin >> str;

    int isPel = 1;

    for(int i = 0; i < str.length() / 2; i++)  {
        if (str[i] != str[str.length()-i-1]) {
            isPel = 0;
            break;
        }
    }

    cout << isPel;
}