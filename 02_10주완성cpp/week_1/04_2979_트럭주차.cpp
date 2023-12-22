#include <bits/stdc++.h>
using namespace std;

int main() {

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