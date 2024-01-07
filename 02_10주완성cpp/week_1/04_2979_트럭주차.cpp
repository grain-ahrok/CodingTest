#include <bits/stdc++.h>
using namespace std;

void my_sol() {
    int a, b, c;
    cin >> a >> b >> c;

    int alpa, omega = 0;
    int time[100] = {0, };
    for(int cnt = 0; cnt < 3; cnt++) {

        cin >> alpa >> omega;
        for(int i = alpa; i < omega; i++) {
            time[i] ++;
        }
    }

    int total = 0;
    for(int i : time) {
        if(i == 1) total += 1*a;
        else if(i == 2) total += 2*b;
        else if(i == 3) total += 3*c;

    }
    cout << total;
}

void t_sol() {
    int A, B, C, a, b, cnt[104], ret;
    cin >> A >> B >> C;
    for(int i = 0; i < 3; i++) {
        cin >> a >> b;
        for(int j = a; j <=b; j++) cnt[j]++;
    }
    for(int j = 1; j < 100; j++) {
        if(cnt[j]) {
            if(cnt[j] = 1) ret += A;
            else if (cnt[j] == 2) ret += B * 2;
            else if (cnt[j] == 3) ret += C * 3;
        }
    }
    cout << ret << "\n";
    return 0;
}

int main() {

}