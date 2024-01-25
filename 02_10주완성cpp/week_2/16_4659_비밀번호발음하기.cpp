#include <bits/stdc++.h>
using namespace std;

vector<char> aeiou = {'a', 'e', 'i', 'o', 'u'};

int vcnt, lcnt;
char pre;
string word;

bool is_vowel(char c) {
    return c=='a' || c=='e' || c=='i' || c=='o' || c=='u';
}

int main() {
    cin.tie(NULL); cout.tie(NULL);
    while(true) {
        cin >> word;
        if(word == "end") return 0;
        bool is_include_v = 0;
        bool flag = 0;
        vcnt = 0; lcnt = 0;
        for(int i = 0; i < word.length(); i++) {
            if(is_vowel(word[i])) vcnt++; lcnt=0; is_include_v = 1;
            else lcnt++, vcnt=0;
            if(vcnt == 3 || lcnt == 3) flag = 1;
            if(i>0 && pre==word[i] && word[i]!='e' && word[i]!='o') flag = 1;
            pre = word[i];
        }
        if(is_include_v == 0) flag = 1;
        if(flag == 0) cout << "<" << word << "> is acceptable." << endl;
        else cout << "<" << word << "> is not acceptable." << endl;
    }
    return 0;
}