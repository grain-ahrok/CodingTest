#include <iostream>
#include <string.h>
using namespace std;

int main( ) {
    
    int cnt;
    cin >> cnt;

    string str1; 
    for(int i = 0; i < cnt; i++) {
        cin >> str1;
        int num = str1.length();
        cout << str1[0] << str1[num-1] << endl;
    }
    

    
}