#include <bits/stdc++.h>
using namespace std;


int N;
string str;
int maxV = INT_MIN;


int cal(int a, int b, char chr) {
    if(chr == '+') return a+b;
    if(chr == '-') return a-b;
    if(chr == '*') return a*b;
}


// idx 는 짝수만 넘어옴. 숫자의 경우만 넘어옴.
void dfs(int idx, int cur) {  
    if(idx >= N-1) { // 마지막 숫자인 경우 리턴!
        maxV = max(maxV, cur);
        return; 
    }

    // 다음 연산에 괄호가 있는 경우
    if(idx+4 <= N-1) {
        int temp = cal(str[idx+2]-'0', str[idx+4]-'0', str[idx+3]);
        dfs(idx+4, cal(cur, temp, str[idx+1]));
    }
    
    // 괄호 없는 경우
    dfs(idx+2, cal(cur, str[idx+2]-'0', str[idx+1])); 
}


int main() {
    cin >> N;
    cin >> str;

    dfs(0, str[0]-'0');
    cout << maxV << "\n";
}
