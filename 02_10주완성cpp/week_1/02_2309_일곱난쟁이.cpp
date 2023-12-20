#include <bits/stdc++.h>
using namespace std;

int n = 9, k = 7;
vector<int> h;
//  // 재귀함수로 풀기


// case1 : make permutation으로 풀기
void case1() {
    vector<int> height;
    int temp;
    for(int i = 0; i < n; i++) {
        cin >> temp;
        height.push_back(temp);
    }
    sort(height.begin(), height.end());
    do {
        if(accumulate(height.begin(), height.begin()+7, 0) == 100) {
            for(int i = 0; i < 7; i++) cout << height[i] << " ";
            return;
        }
    } while(next_permutation(height.begin(), height.end()));
}

// nCr = nCn-r 을 이용해서 풀기,
void case2() {
    vector<int> height;
    int temp;
    for(int i = 0; i < n; i++) {
        cin >> temp;
        height.push_back(temp);
    }
    sort(height.begin(), height.end());
    int sum = accumulate(height.begin(), height.end(), 0);

    pair<int, int> ret;
    for(int i = 0; i < n; i++) {
        for(int j = i+1; j < n; j++ ) {
            if(height[i]+height[j] == sum-100) {
                ret = {i, j};
            } 
        }
    }

    for(int i = 0; i < n; i ++) {
        if(ret.first == i || ret.second == i ) continue;
        cout << height[i] << " ";
    }
}

// 재귀함수로 풀기
void combine(int start, vector<int> v) {
    if(v.size() == k && accumulate(v.begin(), v.end(), 0) == 100) {
        for(int a : v) cout << a << " ";
        exit(0);
        return;
    }

    for(int i = start+1; i < n; i++) {
        v.push_back(h[i]);
        combine(i, v);
        v.pop_back();
    }
    return;
}

void case3() {
    int temp;
    for(int i = 0; i < n; i++) {
        cin >> temp;
        h.push_back(temp);
    }
    sort(h.begin(), h.end());

    vector<int> v;
    combine(-1, v);
    return;
}



int main() {
    case3();

    return 0;
}