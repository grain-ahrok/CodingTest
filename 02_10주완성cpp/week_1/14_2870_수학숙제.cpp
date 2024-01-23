#include <bits/stdc++.h>
using namespace std;

// 1. 한줄 입력을 받음
// 2-1. 반복문을 돌리며 숫자를 string 배열로 나타냄
// 2-2. string이 끝나면 int로 전환해서 vector에 넣기
// 3. sort 후 출력

int N;
vector<string> ret;
string word, snum;

bool isNum(char c) {
    return c >= '0' && c<='9';
}

string sToNum(string s) {
    while(s[0]=='0' && s.size()!=1) {
        s = s.substr(1);
    }
    return s;
}

bool cmp(string a, string b) {
    // if(a.size() != b.size()) return a.size() < b.size();
    // for(int i = 0; i < a.size(); i++) {
    //     if(a[i] != b[i]) return a[i] < b[i];
    // }
    // return a < b;
    if(a.size() == b.size()) return a < b;
    return a.size() < b.size();
}

int main() {
    cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    for(int cnt = 0; cnt < N; cnt++) {
        cin >> word;
        snum = "";
        for(int i = 0; i < word.size(); i++) {
            if (isNum(word[i])) {
                snum += word[i];
            } else if (snum.size()){
                ret.push_back(sToNum(snum));
                snum = "";
            }
        }
        if(snum.size()) ret.push_back(sToNum(snum));
    }
    sort(ret.begin(), ret.end(), cmp);
    for(auto it : ret) cout << it << endl;
    return 0;
}


