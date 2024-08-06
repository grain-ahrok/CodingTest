#include <bits/stdc++.h>
using namespace std;

#define MAX_INT 2000000000

long long A, B;
int res = MAX_INT;

void dfs(long long a, int cnt) {

    if(a > B || a > MAX_INT) return;
    if(a == B) {
        cnt++;
        res = min(cnt, res);
        return;
    }
    dfs(a*2, cnt+1);
    dfs(a*10+1, cnt+1);
}

int main () {
    
    cin >> A >> B;
    dfs(A, 0);

    if(res == MAX_INT) {
        cout << -1;
    } else {
        cout << res;
    }

}

