#include <bits/stdc++.h>
#include <iostream>
using namespace std; 

// factorial 백준 27433
long long factorial(long long a) {
    if(a == 0 || a == 1) return 1;
    return a * factorial(a-1);
}

// 피보나치 합 구하기
int fibonacci(int a) {
    if(a == 0 || a == 1) return a;
    return fibonacci(a-1) + fibonacci(a-2);
}

int main() {
    
    // int num;
    // cin >> num;
    // cout << factorial(num) << endl;

    int num2;
    cin >> num2;
    cout << fibonacci(num2);

    return 0; 
}