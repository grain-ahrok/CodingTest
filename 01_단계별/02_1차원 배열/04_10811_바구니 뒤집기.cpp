#include <iostream>

using namespace std;

int main() {

    int size, cnt;
    cin >> size >> cnt;

    int array[size+1]; 
    for(int i = 0; i < size+1; i++) {
        array[i] = i;
    }

    int num1, num2, changeCnt, temp;
    for(int i = 0; i <cnt; i++) {
        cin >> num1 >> num2;

        changeCnt = (num2 - (num1-1))/2;
        for(int j = 0; j < changeCnt; j++) {
            temp = array[num1 + j];
            array[num1 + j] = array[num2 - j];
            array[num2 - j] = temp;
        }
    }

    for(int j = 1; j < size+1; j++) {
            cout << array[j] << " ";
        }
}
