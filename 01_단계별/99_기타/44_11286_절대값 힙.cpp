#include <bits/stdc++.h>
using namespace std;

int main() {

    priority_queue<int> mq;
    priority_queue<int, std::vector<int>, std::greater<int>> pq;

    int N, temp;
    cin >> N;

    for(int i = 0; i < N; i++) {
        cin >> temp;
        if(temp < 0) {
            mq.push(temp);
        } else if(temp > 0) {
            pq.push(temp);
        } else {
            if(mq.empty() && pq.empty()){
                cout << 0 <<"\n";
            } else if(mq.empty()) {
                cout << pq.top() << "\n";
                pq.pop();
            } else if(pq.empty()) {
                cout << mq.top() << "\n";
                mq.pop();
            } else {
                if(abs(pq.top()) < abs(mq.top())){
                    cout << pq.top() << "\n";
                    pq.pop();
                } else if(abs(pq.top()) > abs(mq.top())) {
                    cout << mq.top() << "\n";
                    mq.pop();
                } else {
                    cout << mq.top() << "\n";
                    mq.pop();
                }
            }

        }
    }

}