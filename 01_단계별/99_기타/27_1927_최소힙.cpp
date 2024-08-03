#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);

    int N, temp; 
    cin >> N; 
    multiset<int> s;

    for(int i = 0; i < N; i++) {
        cin >> temp;

        if(temp == 0) {
            if(s.size() == 0) cout << "0\n";
            else {
                cout << *s.begin() << "\n";
                s.erase(s.begin());
            }
        }
        else {
            s.insert(temp);
        }
    }
}