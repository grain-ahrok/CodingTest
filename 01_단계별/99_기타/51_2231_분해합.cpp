#include <bits/stdc++.h>
using namespace std;

int main() {

    int N, tmp;
    cin >> N;
    int k = 1;
    
    for(int i = N*0.5; i < N; i++) {

        tmp = i;
        k = 1;
        while(i / k) {
            
            tmp += (i / k) % 10; 
            k *= 10;
        }

        if(tmp == N) {
            cout << i;
            return(0);
        }
        

    }
    cout << 0;

}