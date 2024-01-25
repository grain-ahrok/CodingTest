#include <bits/stdc++.h>
using namespace std;

int N;
unsigned long long num;
unsigned long long ret;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> N;

    for(int cnt = 0; cnt < N; cnt++) {
        ret = 0;
        cin >> num;
        while(num/=5) {
            ret += num;
        }
        // endl 은 내부 버퍼를 비워주는 역할, \n은 단순 개행 문자. 
        // 따라서 \n이 더 빠르다.
        cout << ret << "\n";
    }
}