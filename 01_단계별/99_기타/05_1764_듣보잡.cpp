#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    int N, M;
    cin >> N >> M;

    map<string, bool> m;
    string temp;
    for(int i = 0; i < N; i++) {
        cin >> temp;
        m[temp] = 1;
    }

    vector<string> s;

    for(int i = 0; i < M; i++) {
        cin >> temp;
        if(m.find(temp) != m.end()) {
            s.push_back(temp);
        }
    }
    cout << s.size() << "\n";
    sort(s.begin(), s.end());
    for(auto str : s) {
        cout << str << "\n";
    }
}