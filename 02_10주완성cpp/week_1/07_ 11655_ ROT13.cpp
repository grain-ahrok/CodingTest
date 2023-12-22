#include <bits/stdc++.h>
using namespace std;

int main() {

    string str;
    getline(cin, str, '\n');

    string buf = str;
    
    int temp;
    for(int i = 0; i < str.length(); i++) {
        if(str[i] >= 'a' && str[i] <='z') {
            temp = (str[i] - 'a' + 13) % 26 + 'a';
            buf[i] = (char)temp;
        } else if(str[i] >= 'A' && str[i] <='Z') {
            temp = (str[i] - 'A' + 13) % 26 + 'A';
            buf[i] = (char)temp;
        }
    }

    cout << buf;
}