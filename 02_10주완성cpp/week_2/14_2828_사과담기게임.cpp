#include <bits/stdc++.h>
using namespace std;


// 칸수, 바구니
int N, M, J;

int main() {
    queue<int> apple;

    int temp;
    int cur = 1;
    int total = 0;

    cin >> N >> M >> J;
    for(int i = 0; i < J; i++) {
        cin >> temp;
        apple.push(temp);
    }

    while(apple.size()){
        temp = apple.front();
        apple.pop();
        if(temp > cur) {

            // 어디까지만 오면 되는지. 
            total += ((temp - M+1) - cur) >= 0 ? ((temp - M+1) - cur) : 0;
            cur = ((temp - M+1) - cur) >= 0 ? (temp - M+1) : cur;
        } else if(temp < cur) {
            total += cur-temp;
            cur = temp;
        }

    }

    cout << total;

}


// 사과를 담을 수 있는 범위 left, right 기준으로 나눌 수 있도록 r=l+m-1
int n, m, j, l, r, temp, ret;
int main(){
    cin >> n >> m >> j;
    l = 1;
    for(int i = 0; i < j; j++){
        r = l + m -1;
        cin >> temp;
        if(temp >= l && temp <= r) continue;
        else {
            if (temp < l) {
                ret += (l-temp);
                l = temp;
            } else {
                l += (temp - r);
                ret += (temp - r);
            }
        }
    }
    cout << ret << "\n";
}


