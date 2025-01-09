#include <bits/stdc++.h> 
using namespace std;

// 부분 수열 자체 구하기

int N, a[1001], b[1001], prev_list[1001];

int main() {
    cin >> N; 

    for(int i = 0; i < N; i++) {
        prev_list[i] = -1;
    }

    for(int i = 0; i < N; i++) {
        cin >> a[i];
    }  

    int max_v=-1, max_idx=-1;
    for(int i = 0; i < N; i++) {
        int tmp = 0, idx=-1;
        for(int j = 0; j < i; j++) {
            if(a[j] < a[i] && tmp < b[j]) {
                tmp = b[j];
                idx = j;
            }
        }
        b[i] = tmp + 1;
        prev_list[i] = idx;
        if(max_v < b[i]) max_idx = i;
    }

    vector<int> v;
    while(true) {
        v.push_back(a[max_idx]);
        max_idx = prev_list[max_idx];
        if(max_idx < 0) break;
    }


    
    reverse(v.begin(), v.end());

    for(int item : v) {
        cout << item << " ";
    }

    return 0;
}