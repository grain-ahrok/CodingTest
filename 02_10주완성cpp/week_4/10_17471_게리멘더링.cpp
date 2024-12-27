#include <bits/stdc++.h>
using namespace std;


bool linked[11][11]; 
int visited[11];
int pp_list[11], pp_sum = 0;
int N, temp1, temp2;

int num;

void print_queue(std::queue<int> q)
{
  while (!q.empty())
  {
    std::cout << q.front() << " ";
    q.pop();
  }
  std::cout << std::endl;
}


int main() {

    cin >> N;
    // 인구수 받고, 총합 구하기
    for(int i = 1; i < N+1; i++) {
        cin >> pp_list[i];
        pp_sum += pp_list[i];
    }

    // 연결된 마을 map 구하기
    for(int i = 1; i < N+1; i++) {
        cin >> temp1;
        for(int j = 0; j < temp1; j++) {
            cin >> temp2;
            linked[i][temp2] = 1;
        }
    }

    // // 출력 확인
    // for(int i = 1; i<= N; i++) {
    //     for(int j = 1; j<= N; j++) {
    //         cout << linked[i][j] << " ";
    //     }
    //     cout << "\n";
    // }


    int check = 0;
    int res = pp_sum;
    for(int num = 1; num < (1<<N)-2; num++) {
        // 0과 1로 두 부분을 나눈다. 
        // 반으로 쪼개져 있는지 확인한다.
        temp1 = 0; 
        temp2 = 0;

        
        check = num;
        queue<int> q;
        for(int i = 0; i < N; i++) {
            if(((check>>i) & 1) == 0 ) {
                q.push(i+1);
                temp1 += pp_list[i+1];
                check ^= (1<<i);

                while(q.size()){
                    int x = q.front();
                    q.pop();
                    
                    for(int j = 1; j <= N; j++) {
                        if(linked[x][j] && ((check >> (j-1) & 1) == 0)) {
                            q.push(j);
                            check ^= 1<<(j-1);
                            temp1 += pp_list[j];
                        }
                    }
                }
                break;
            }
        }
        if(check != (1<<N)-1) continue;


        check = num;
        queue<int> q2;
        for(int i = 0; i < N; i++) {
            if((check>>i) & 1) {

                q2.push(i+1);
                temp2 += pp_list[i + 1];
                check ^= (1 << i);

                while (q2.size()) {
                    int x = q2.front();
                    q2.pop();

                    for(int j = 1; j <= N; j++) {
                        if(linked[x][j] && ((check >> (j-1)) & 1) == 1) {
                            q2.push(j);
                            temp2 += pp_list[j];
                            check ^= (1 << (j-1));
                        }
                    }
                }
                break;
            }
        }

        if(temp1 + temp2 == pp_sum) {
            res = min(abs(temp1-temp2), res);
        }
    }

    if(res == pp_sum) {
        cout << -1;
    } else {
        cout << res;
    }

}