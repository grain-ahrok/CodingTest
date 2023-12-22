#include <bits/stdc++.h>
using namespace std;


void sol1() {
    map<char, int> m;
    string alph = "abcdefghijklmnopqrstuvwxyz";
    for(char a : alph) m.insert({a, 0});

    string input;
    cin >> input;
    for(char a : input) m[a] += 1;

    for(auto item : m) cout << item.second << " ";
}


void sol2() {
    int cnt[26] = {0, };
    string str;
    cin >> str;
    
    for(char a : str) cnt[a-'a']++;
    for(int c : cnt) cout << c << " ";
}

int main() {
    sol2();
}