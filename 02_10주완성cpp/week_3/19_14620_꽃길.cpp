#include <bits/stdc++.h>
using namespace std;



int mmap[11][11];
int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};

int msum(int y, int x) {
    int sum = mmap[y][x];
    for(int i = 0; i < 4; i++) {
        sum += mmap[y+dy[i]][x+dx[i]];
    }
    return sum;
}


int main(){
    
    int sum, res = 0, N;
    vector<pair<int,int>> v;
    cin >> N;

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            cin >> mmap[i][j];
            res += mmap[i][j];
        }
    }

    // 가능한 꽃 위치 vector에 푸쉬!
    for(int i = 1; i < N-1; i++) {
        for(int j = 1; j < N-1; j++) {
            v.push_back({i,j});
        }
    }
    

    for(int i = 0; i < v.size()-2; i++) {
        sum = msum(v[i].first, v[i].second);
        for(int j = i+1; j < v.size()-1; j++) {
            
            if((abs(v[i].first-v[j].first) + abs(v[i].second-v[j].second)) <= 2 ) continue;
            sum += msum(v[j].first, v[j].second);

            for(int k = j+1; k< v.size(); k++) {
                if(abs(v[i].first - v[k].first) + abs(v[i].second - v[k].second) <= 2 ) continue;
                if(abs(v[j].first - v[k].first) + abs(v[j].second - v[k].second) <= 2 ) continue;
                sum += msum(v[k].first, v[k].second);
                res = min(res, sum);
                sum -= msum(v[k].first, v[k].second);
            }
            sum -= msum(v[j].first, v[j].second);
        }
    }

    cout << res;

}