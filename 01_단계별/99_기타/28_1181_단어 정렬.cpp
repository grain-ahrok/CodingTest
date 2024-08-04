#include <bits/stdc++.h>
using namespace std;


int compare(string &a, string &b) {
    if(a.length() < b.length()) {
        return 1;
    } else if(a.length() > b.length()) {
        return 0;
    } else {
        return a < b;
    }
}

int main() {

    int N;
    cin >> N;
    vector<string> v;
    string temp;

    for(int i = 0; i < N; i++) {
        cin >> temp;
        v.push_back(temp);
    }
    sort(v.begin(), v.end(), compare);
    v.resize(unique(v.begin(), v.end())- v.begin());

    for(auto item : v) {
        cout << item << "\n";
    }

}