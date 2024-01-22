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