#include <bits/stdc++.h>
using namespace std;

//g++ -std=c++14 -Wall 02_next_permutation.cpp -o test
int main() {

    vector<int> v = {2, 1, 3};
    sort(v.begin(), v.end());
    do {
        for(int n : v) cout << n << " ";
        cout << endl;
    } while(next_permutation(v.begin(), v.end()));
}