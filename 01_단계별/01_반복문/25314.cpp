#include <iostream>

using namespace std;

int main() {

    int number; 
    cin >> number;

    int count = number / 4;
    if(number % 4 != 0) {
        count ++;
    }

    for(int i = 0; i < count; i++) {
        cout << "long ";
    }
    cout << "int";

}