// https://www.acmicpc.net/problem/9934
// https://www.inflearn.com/course/lecture?courseSlug=10%EC%A3%BC%EC%99%84%EC%84%B1-%EC%BD%94%EB%94%A9%ED%85%8C%EC%8A%A4%ED%8A%B8-%ED%81%B0%EB%8F%8C&unitId=100369&tab=curriculum

#include <bits/stdc++.h>
using namespace std;

int depth;
vector<int> nums;
vector<int> tree[10];


void go(int s, int e, int level) {
    if(s > e) return;
    if(s == e) {
        tree[level].push_back(nums[s]); 
        return;
    }
    int mid = (s+e)/2;
    tree[level].push_back(nums[mid]);

    go(s, mid-1, level+1);
    go(mid+1, e, level+1);
}

int main() {
    int temp;

    cin >> depth;
    for(int i = 0; i < pow(2,depth)-1; i++) {
        cin >> temp;
        nums.push_back(temp);
    }

    go(0, nums.size()-1, 0);


    for(int i = 0 ; i < depth; i++) {
        for(int a : tree[i]) {
            cout << a << " ";
        }
        cout << "\n";
    }
}