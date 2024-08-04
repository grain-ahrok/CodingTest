#include <bits/stdc++.h>
using namespace std;

int main() {
    string cmd;
    int N, temp;
    queue<int> q;

    cin >> N;
    for(int i = 0; i < N; i++) {
        cin >> cmd;
        
        if(cmd == "push") {
            cin >> temp;
            q.push(temp);
        }else if( cmd == "front") {
            if(q.size() == 0) {
                cout << -1 << "\n";
            } else {
                cout << q.front() <<"\n";
            }
        }else if(cmd == "back") {
            if(q.size() == 0) {
                cout << -1 << "\n";
            } else {
                cout << q.back() <<"\n";
            }
        } else if(cmd == "size") {
            cout << q.size() << "\n";
        } else if(cmd == "empty") {
            cout << q.empty() << "\n";
        } else if (cmd == "pop") {
            if(q.size() == 0) {
                cout << -1 << "\n";
            } else {
                cout << q.front() << "\n";
                q.pop();
            }
        }

    }
}
