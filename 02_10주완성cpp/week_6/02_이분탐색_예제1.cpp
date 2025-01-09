#include <bits/stdc++.h>
using namespace std;

int binarySearch(const vector<int>& v, int target) {
    int left = 0;
    int right = v.size()-1;

    while(left <= right) {
        int mid = (left + right) / 2;
        if(v[mid] < target) {
            left = mid + 1;
        } else if(v[mid] > target) {
            right = mid -1;
        } else {
            return mid;
        }

    }
    return -1;
}

int main() {
    int T;
    cin >> T;
    

    while(T--) {
        vector<int> v;
        vector<int> v2;
        int cnt, tmp;

        cin >> cnt;
        for(int i = 0; i < cnt; i++) {
            cin >> tmp;
            v.push_back(tmp);
        }
        sort(v.begin(), v.end());

        cin >> cnt;
        for(int i = 0; i < cnt; i++) {
            cin >> tmp;
            v2.push_back(tmp);
        }

        for(int item : v2) {
            int ret = binarySearch(v, item);
            if(ret > 0) cout << "큰돌이는 기억해!\n";
            else cout << "큰돌이는 까먹었어!\n";
        }
    }
    return 0;
}