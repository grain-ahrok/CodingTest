#include <bits/stdc++.h>
using namespace std;
#define prev kundol
int n, o, A=0, B=0, asum=0, bsum=0;
string s, prev;

void print(int a) {
    string d = "00" + to_string(a/60);
    string e = "00" + to_string(a%60);
    cout << d.substr(d.size()-2 , 2) << ":" << e.substr(e.size()-2 , 2) << "\n";
}


int changeToInt(string a) {
    return stoi(a.substr(0, 2)) * 60 + stoi(a.substr(3));
}

void go(int &sum, string s){
    sum += changeToInt(s) - changeToInt(prev);
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> o; cin >> s;
        if(A>B) go(asum, s);
        else if(B>A) go(bsum, s);
        o == 1 ? A++ : B++;
        prev = s;
    }

    if(A>B) go(asum, "48:00");
    else if(B>A) go(bsum, "48:00");

    print(asum);
    print(bsum);
    return 0;
}