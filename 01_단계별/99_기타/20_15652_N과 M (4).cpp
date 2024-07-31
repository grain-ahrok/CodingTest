#include <bits/stdc++.h>
using namespace std;


int N, K;
vector<int> v;
void combi(int start) {
    if(v.size() == K) {
        for(auto i : v) cout << i << " ";
        cout << "\n";
        return;
    }

    for(int i = start; i <= N; i++) {
        v.push_back(i);
        combi(i);
        v.pop_back();
    }

}

int main() {

    cin >> N >> K;
    combi(1);

}