#include <iostream>

using namespace std;

int main() {

    int size, cnt; 
    cin >> size >> cnt;

    int array[size];

    for(int i = 1; i <= size; i++) {
        array[i-1] = i;
    }

    int num1, num2, temp;
    for(int i = 0; i < cnt; i++) {
        cin >> num1 >> num2;
        temp = array[num1-1];
        array[num1-1] = array[num2-1];
        array[num2-1] = temp;
    }

    for(int i = 0; i < size; i++) {
        cout << array[i] << " ";
    }



}