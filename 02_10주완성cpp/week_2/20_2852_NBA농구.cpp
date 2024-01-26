#include <bits/stdc++.h>
using namespace std;

int N;
int ttime1, ttime2;

int inp_time, cal_time;
int win, score1 = 0, score2 = 0, temp;
string s_time;


int main() {

    cin >> N;
    for(int cnt = 0; cnt < N; cnt++) {
        cin >> temp;
        cin >> s_time;
        inp_time = stoi(s_time.substr(0,2)) * 60 + stoi(s_time.substr(3));

        if(temp==1) {
            score1++;
        }
        else if (temp==2) {
            score2++;
        }

        // 이기고 있는 팀이 골을 넣은 경우
        // 비기게 된 경우
        // 역전된 경우
        if(win == 0) {  // 비기고 있었던 경우
            cal_time = inp_time;
            win = temp;
        } else if(win == 1) {   // 1팀이 이기고 있었던 경우
            if(score1 == score2) {  
                ttime1 += (inp_time - cal_time);
                win = 0;
            }
        } else if(win == 2) {   // 2팀이 이기고 있었던 경우
            if(score1 == score2) {
                ttime2 += (inp_time - cal_time);
                win = 0;
            }
        }

    }

    if(win == 1) {
        ttime1 += (2880 - cal_time);
    } else if (win == 2) {
        ttime2 += (2880 - cal_time);
    }

    cout << setw(2) << setfill('0') << ttime1/60 << ":" << setw(2) << setfill('0') << ttime1%60 << "\n";
    cout << setw(2) << setfill('0') << ttime2/60 << ":" << setw(2) << setfill('0') << ttime2%60;

}

