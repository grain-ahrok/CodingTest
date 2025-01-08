// 첫째 줄에 골동품의 수 N과 가방의 수 K가 주어집니다. (1 ≤ N,K ≤ 300,000)
// 다음 N개의 줄에는 각 골동품의 정보(M[i], V[i])가 주어집니다. (0 ≤ M[i], V[i] ≤ 1,000,000)
// 다음 K개의 줄에는 가방에 담을 수 있는 최대 무게 C[i]가 주어집니다. (1 ≤ C[i] ≤ 100,000,000)

// 가방의 낮은 무게 부터 담을 수 있는 사용한다.
// 우선 순위 큐 사용.

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n, k, ret = 0;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> k;

    vector<pair<ll, ll>> v(n);
    vector<ll> c(k);
    for(int i = 0; i < n; i++) {
        cin >> v[i].first >> v[i].second;
    }

    for(int i = 0; i < k; i++) {
        cin >> c[i];
    }

    sort(v.begin(), v.end());   // 무게, 가치 오름차순 정렬
    sort(c.begin(), c.end());   // 가방 수용 무게 오름 차순 정렬

    priority_queue<ll> pq;
    int j = 0;
    for(int i = 0; i < k; i++) {
        while(j < n && v[j].first <= c[i]) {
            pq.push(v[j].second);
            j++;
        }
        ret += pq.top();
        pq.pop();
    }
    
    cout << ret;
    return 0;

}

