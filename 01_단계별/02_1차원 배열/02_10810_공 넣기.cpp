#include <iostream>
#include <string.h>

using namespace std;

int main()
{

    int size, cnt;
    cin >> size >> cnt;

    int array[size];
    memset(array, 0, sizeof(int) * size);

    int i, j, k;
    for (int index = 0; index < cnt; index++)
    {
        cin >> i >> j >> k;
        for (int _i = i; _i <= j; _i++)
        {
            array[_i - 1] = k;
        }
    }
    for (int index2 = 0; index2 < size; index2++)
    {
        cout << array[index2] << " ";
    }
}