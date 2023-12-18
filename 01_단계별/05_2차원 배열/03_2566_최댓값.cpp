#include <bits/stdc++.h>
using namespace std;

//g++ -std=c++14 -Wall 02_next_permutation.cpp -o test
int main() {
    int mX = 0; 
    int mY = 0;
    int maxValue = 0;
    int curValue = 0;

    for(int i = 0; i < 9; i++) {
        for(int j = 0; j < 9; j++) {
            cin >> curValue;
            if(curValue > maxValue) {
                mX = j;
                mY = i;
                maxValue = curValue;
            }
        }
        
    }

    cout << maxValue << endl;
    cout << mY+1 << " " << mX+1;

}