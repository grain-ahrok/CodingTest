#include <bits/stdc++.h>
using namespace std;

int ret = INT_MAX;
int N, M, a[300001];


bool search(int num) {

    int n = 0;
    
    for(int i = 0; i < M; i++) {
        n += a[i]/num;
        if(a[i] % num > 0) n++;
    }

    return n <= N;
    
}

int main() {

    cin >> N >> M;

    int left=1, right, mid;
    for(int i = 0; i < M; i++) {
        cin >> a[i];
        right = max(right, a[i]);
    }

    while(left <= right) {
        mid = (left + right)/2;
        if(search(mid)) {
            right = mid -1;
            ret = mid;
        } else {
            left = mid + 1;
        }
    }

    cout << ret;
    return 0; 
}
