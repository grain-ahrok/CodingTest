//     *
//    ***
//   *****
//  *******
// *********
//  *******
//   *****
//    ***
//     *


#include <iostream>
using namespace std;

int main() {
    
    int count; 
    cin >> count;

    // 첫번째 줄
    for (int i = 1; i <= count; i++) {
        for(int j = 0; j < count - i; j++) {
            cout << " ";
        }
        for(int j = 0; j < 2*i -1; j++) {
            cout << "*";
        }
        cout << endl;
    }
      for (int i = 1; i < count; i++) {
        for(int j = 0; j < i; j++) {
            cout << " ";
        }
        for(int j = 0; j < 2*(count-i) -1; j++) {
            cout << "*";
        }
        cout << endl;
    }

    


    
}

