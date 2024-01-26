#include <bits/stdc++.h>
using namespace std;

string str;


bool check(string str) {
    stack<char> s;
    for (int i = 0; i < str.length(); i++) {
        if (str[i] == '(' || str[i] == '[') s.push(str[i]);
        else if (str[i] == ']') {
            if(s.empty() || s.top() != '[') return false;
            s.pop();
        } else if (str[i] == ')' ) {
            if(s.empty() || s.top() != '(') return false;
            s.pop();
        }
    }
    return s.empty();
}


int main() {
    while(true) {
        getline(cin, str);
        if(str == ".") break;
        cout << (check(str) ? "yes" : "no" ) << "\n";
    }
    return 0;
}