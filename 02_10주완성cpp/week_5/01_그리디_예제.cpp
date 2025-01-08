// 그리디 알고리즘은 문제를 해결할 때 각 단계에서 그 순간에 최선이라고 생각되는 선택을 하는 방식으로, 이 과정에서 얻은 선택들이 모여 전체 문제에 대한 최적의 해를 구하는 알고리즘입니다.
// 즉, 그리디 알고리즘은 지역적 최적해를 찾는 과정에서, 이를 모아 전역적 최적해를 구하는 방식입니다. 다만, 모든 경우에 전역 최적해를 보장하지는 않습니다.
// 명제가 틀릴경우 틀릴 확률이 높기 때문에 가장 마지막에 사용하는 방법이다.

#include <bits/stdc++.h>
using namespace std;

int from, to, n, ret = 1;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<pair<int, int>> v;

    cin >> n; 
    for(int i = 0; i < n; i++) {
        cin >> from >> to;
        v.push_back({to, from});
    }

    sort(v.begin(), v.end());
    from = v[0].second;
    to = v[0].first;

    for(int i = 1; i < n; i++) {
        if(v[i].second < to) continue;
        from = v[i].second;
        to = v[i].first;
        ret++;
    }

    cout << ret;
    return 0;
}