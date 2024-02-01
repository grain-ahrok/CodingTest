#include <bits/stdc++.h>
using namespace std;

int N, M;
vector<pair<int, int>> home;
vector<pair<int, int>> chicken;
int totalMin = 2500;


void getMinD(vector<pair<int, int>> v) {
    int total = 0;
    for(auto ih : home) {
        vector<int> temp;
        for(auto ic : v) {
            temp.push_back(abs(ih.first - ic.first) + abs(ih.second - ic.second));
        }
        total += *min_element(temp.begin(), temp.end());
    }
    if(totalMin > total) totalMin = total;
}

void combine(int start, vector<pair<int, int>> v) {
    if(v.size() == M) {
        // for(auto it : v) cout << "{" << it.first << ", " << it.second << "}" << "  ";
        getMinD(v);
        return;
    }

    for(int i = start+1; i < chicken.size(); i++) {
        v.push_back(chicken[i]);
        combine(i, v);
        v.pop_back();
    }
}


int main() {
    cin.tie(NULL); cout.tie(NULL);
    cin >> N >> M;
    int temp;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++){
            cin >> temp;
            if(temp == 1) home.push_back({i, j});
            if(temp == 2) chicken.push_back({i, j});
        }
    }

    vector<pair<int, int>> v;
    combine(-1, v);
    cout << totalMin;
    return 0;
}