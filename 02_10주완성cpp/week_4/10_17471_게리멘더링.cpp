#include <bits/stdc++.h>
using namespace std;


bool linked[11][11]; // 행 번호 : 지역구 순서, 열번호 : 연결되어 있는 지역구인지 아닌지
int visited[11], check_visited[11];
int ppltn[11], total_pp = 0, sum_pp = 0, res = 0; // 인구수, 인구수 총합, dfs 중 인구수 합계
int N, temp1, temp2;


// 1. 연결되어 있는 지역구 나타내기.
// 2-1. 연결되어 있는 것을 하나씩 넣고 빼고를 반복. // dfs가 적절해 보임.
// 2-2. 현재 지역보다 작은 숫자는 들리지 않음.
// 2-2. 인구수 더하고 차를 구하기
// 이걸 비트마스킹으로 어떻게 풀지?

// 나머지가 연결되어 있는지 체크
bool check(int prv) {
    int start = 0;
    for(int i = 1; i <= N; i++) {
        if(check_visited[start] != 1) {
            start = i;
            break;
        }
    }

    queue<int> q;
    cout << "동작하긴 합니다만" << start << "\n";
    q.push(start);
    while(q.size()) {
        int prv = q.front();
        check_visited[prv] = 1;
        q.pop();
        for(int i = 1; i <= N; i++) {
            if(check_visited[i] == 1) continue;
            if(linked[prv][i] == 0) continue;
            q.push(i);
        }
    }

    for(int i = 1; i <= N; i++) {
        if(check_visited[i] != 1) return false; 
    }

    queue<int> q1;
    q1.push(start);
    while(q1.size()) {
        int prv = q.front();
        check_visited[prv] = 1;
        q.pop();
    }
    return true;
}

void dfs(int start, int cnt){
    // 출력 확인
    cout << start << ":" << sum_pp << "\n";
    for(int i = 1; i <= N; i++) cout <<  visited[i] << " ";
    cout << "\n";
    
    if(cnt >= N-2) return;
    if(cnt > 1 && cnt < N-1) {
        int check_i = abs(total_pp-(2*sum_pp));
        memcpy(check_visited, visited, N+1);
        if( res>check_i && check(start) ) {
            res = min(check_i, res);
        }
    }

    for(int i = 1; i <= N; i++) {
        if(linked[start][i] == 0 || visited[i] != 0) continue;
        visited[i] = 1;
        sum_pp += ppltn[i];
        dfs(i, cnt + 1); 
        sum_pp -= ppltn[i];
        visited[i] = 0;

    }
}


int main() {

    cin >> N;
    // 인구수 받고, 총합 구하기
    for(int i = 1; i < N+1; i++) {
        cin >> ppltn[i];
        total_pp += ppltn[i];
    }
    res = total_pp;

    // 연결된 마을 map 구하기
    for(int i = 1; i < N+1; i++) {
        cin >> temp1;
        for(int j = 0; j < temp1; j++) {
            cin >> temp2;
            linked[i][temp2] = 1;
        }
    }

    // 출력 확인
    for(int i = 1; i<= N; i++) {
        for(int j = 1; j<= N; j++) {
            cout << linked[i][j] << " ";
        }
        cout << "\n";
    }

    // dfs로 마을 탐색하여 인구 차 구하기
    for(int i = 1; i < N; i++) {
        cout << "\n";
        for(int j = 1; j < i; j++) visited[j] = -1;    // 방문할 필요 없는 공간 -1 처리.
        visited[i] = 1;
        sum_pp = ppltn[i];

        dfs (i, 1);

        fill_n(&visited[0], N+1, 0);
    }

    if(res == total_pp) cout << -1;
    else cout << res;

}