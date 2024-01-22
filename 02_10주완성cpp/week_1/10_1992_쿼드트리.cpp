#include <bits/stdc++.h>
using namespace std;

string b[64][64];
string a[64][64];
int N;


void quad_tree(string before[64][64], string after[64][64], int size) {
    if(size == 1) {
        cout << before[0][0];
        return;
    }
    string w,x,y,z;

    for(int i = 0; i < size/2; i++) {
        for(int j = 0; j < size/2; j++) {
            w = before[2*i][2*j];
            x = before[2*i][2*j+1];
            y = before[2*i+1][2*j];
            z = before[2*i+1][2*j+1];
            if(w == "1" && x == "1" && y == "1" && z == "1") {
                after[i][j] = "1";
            } else if (w == "0" && x == "0" && y == "0" && z == "0"){
                after[i][j] = "0";
            } else {
                after[i][j] = "(" + w + x + y + z + ")";
            }
        }
    }

    quad_tree(after, before, size/2);


}

typedef long long int ll;
int n;
string s;
char a[101][101];
string quard(int y, int x, int size) { 
    if(size == 1) return string(1, a[y][x]); // string 으로 변환하는 함수
    char b = a[y][x];
    string ret = "";
    bool flag = 0;
    for(int i = y; i < y + size; i++) {
        for(int j = x; j < x + size; j++) {
            if(b != a[i][j]) {
                ret += '(';
                ret += quard(y, x, size / 2);
                ret += quard(y, x + size / 2, size / 2);
                ret += quard(y + size / 2, x, size / 2);
                ret += quard(y + size / 2, x + size / 2, size / 2);
                ret += ')';
                return ret;
            }
            return string(1, a[y][x]);
        }
    }
}


int main() {
    cin >> N;
    string temp;
    
    for(int i = 0; i < N; i++) {
        cin >> temp;
        for(int j = 0; j < N; j++) {
            b[i][j] = temp[j];
        }
    }

    quad_tree(b, a, N);
}


 


int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> s;
        for(int j = 0; j < n; j++) {
            a[i][j] = s[j];
        }
    }
    cout << quard(0, 0, n) << '\n';
    return 0;
}