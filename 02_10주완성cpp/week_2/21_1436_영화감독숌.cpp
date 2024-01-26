#include <bits/stdc++.h>
using namespace std;

int main() {

    int N, i=666;
    cin >> N;

    for(;;i++) {
        if(to_string(i).find("666") != string::npos) N--;
        if(N == 0) break;
    }

    cout << i;


}