#include <bits/stdc++.h>
using namespace std;
 
int N;
string str;

bool check(string str) {
    int pos;
    while((pos = str.find("()")) != string::npos){
        str.erase(pos, 2);
    }
    if(str.size()) return false;
    else return true;
}

bool check1(string str) {
    stack<char> s;

    for(int i = 0; i < str.length(); i++) {
        if(str[i] == '(') s.push('(');
        else if(s.empty() == false) s.pop();
        else return false;
    }
    return s.empty();
}
 
int main() {
    cin >> N;
    for(int i = 0; i < N; i++) {
        cin >> str;
        cout << (check1(str) ? "YES" : "NO") << "\n";
    }
}