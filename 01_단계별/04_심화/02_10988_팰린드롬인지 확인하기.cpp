#include <iostream>
#include <string.h>
using namespace std;

int main() {
    // level, noon 앞으로 읽을 때와 거꾸로 읽을때가 똑같은단어
    string str1, str2;
    cin >> str1;
    
    str2 = str1;
    char temp;
    for(int i = 0; i < (str2.length()+1)/2; i++) {
        temp = str2[i];
        str2[i] = str2[str2.length()-1 - i];
        str2[str2.length()-1 - i] = temp;
    }
    

    if(str1 == str2) {
        cout << 1;
    } else {
        cout << 0;
    }


    
}

