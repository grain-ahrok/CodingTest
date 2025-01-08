#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// 교수님을 돕기 위해 학생들의 최종 성적이 주어질 때, 성적이 좋지 않은 5명의 학생을 선택하여 성적이 낮은 순서대로 출력하는 프로그램을 작성하세요.

ll n;
double tmp;
int main() {

    cin >> n;
    priority_queue<double> pq;

    for(ll i = 0; i < n; i++) {
        cin >> tmp;
        
        if(pq.size() == 5) {
            pq.push(tmp);
            pq.pop();
        } else {
            pq.push(tmp);
        }
    }

    vector<double> v;
    for(int i = 0; i < 5; i++) {
        v.push_back(pq.top());
        pq.pop();
    }

    sort(v.begin(), v.end());
    for(double it : v) {
        cout << it << " ";
    }

    return 0;
}