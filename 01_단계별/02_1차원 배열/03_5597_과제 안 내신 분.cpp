#include <iostream>

using namespace std;

int main() {
    
    int array[31] = {0,};

    int snum;
    for(int i = 0; i < 28; i++) {
        cin >> snum;
        array[snum] = snum;
    }

    for(int i = 1; i < 31; i++) {
        if(array[i] == 0) {
            cout << i << endl;
        }
    }



}