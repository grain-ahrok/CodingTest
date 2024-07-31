#include <bits/stdc++.h>
using namespace std;


int N, K;
vector<int> nums;
vector<int> v;

void combi(int start) {
    if(v.size() == K) {
        for(auto i : v) cout << i << " ";
        cout << "\n";
        return;
    }

    for(int i = 0; i < N; i++) {
        if(find(v.begin(), v.end(), nums[i]) != end(v)) continue;
        v.push_back(nums[i]);
        combi(i);
        v.pop_back();
    }

}

int main() {

    cin >> N >> K;
    int tmp;
    for(int i = 0; i < N; i++) {
        cin >> tmp;
        nums.push_back(tmp);
    }
    sort(nums.begin(), nums.end());

    combi(0);

}   

