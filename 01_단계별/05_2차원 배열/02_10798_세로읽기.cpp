#include <iostream>
#include <string.h>
using namespace std;

int main() {

    string chars[5];

    for(int i = 0; i < 5; i++) {
        cin >> chars[i];
    }

    for(int i = 0; i < 15; i++) {
        for(int j = 0; j < 5; j++) {
            if ( i < chars[j].length()) {
                cout << chars[j][i];
            }
            
        }
    }

}