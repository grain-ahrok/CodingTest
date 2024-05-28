#include <bits/stdc++.h>
using namespace std;

int N, mp, mf, ms, mv;
int pfsvp[16][5];
vector<int> v;
// price, chosen number
vector<pair<int, string>> res;
vector<string> str;

void checkSum() {
    int temp[5] = {0,};
    string temps = "";
    for(int i : v) {
        temps = temps + to_string(i+1) + " ";
        for(int j = 0; j < 5; j++) {
            temp[j] += pfsvp[i][j];
        }
    }
    // 영양분 기준치 이상인지 확인
    if(temp[0]>=mp && temp[1]>=mf && temp[2]>=ms && temp[3]>=mv) {
        res.push_back({temp[4], temps});
    }
}

// combination
void combine(int k, int start) {
    if(v.size() == k) {
        checkSum();
        return;
    }
    for(int i = start; i < N; i++) {
        v.push_back(i);
        combine(k, i+1);
        v.pop_back();
    }
}

int compare(pair<int, string>& a, pair<int, string>& b) {
    if(a.first != b.first) return a < b;

    istringstream iss_a(a.second);
    istringstream iss_b(b.second);

    int ai, bi;
    while(iss_a >> ai && iss_b >> bi) {
        if(ai < bi) return true;
        if(ai > bi) return false;
    }
    return a.second.size() < b.second.size();
}


int main () {
    cin >> N >> mp >> mf >> ms >> mv;

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < 5; j++) {
            cin >> pfsvp[i][j];
        }
    }

    for(int i = 1; i <= N; i++) {
        combine(i, 0);
    }

    
    if(res.size() == 0) {
        cout << -1 << "\n";
    } else {
        sort(res.begin(), res.end(), compare);
        cout << res[0].first << "\n";
        cout << res[0].second;
    }
}
