#include <bits/stdc++.h>
using namespace std;

int n = 9, k = 7;
vector<int> height;


// TODO : make permutation 으로 풀기, // nCr = nCn-r 을 이요해서 풀기, // 재귀함수로 풀기
void combine(int start, vector<int> v) {
    if (v.size() == k && accumulate(v.begin(), v.end(), 0) == 100 ) {
        for(int a : v) cout << a << "\n";
        exit(0);
    }
    for(int i = start + 1; i < n; i++) {
        v.push_back(height[i]);
        combine(i, v);
        v.pop_back();
    }
}


int main() {
    int temp;
    for(int i = 0; i < 9; i++) {
        cin >> temp;
        height.push_back(temp);
    }
    sort(height.begin(), height.end());
    vector<int> empty;
    combine(-1, empty);
}