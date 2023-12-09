#include <iostream>
#include <string.h>
using namespace std;

int main() {

    string line;


    while(getline(cin, line)) {
        if(line.empty()) {
            break;
        }
        cout << line << endl;
    }

}