#include <bits/stdc++.h>
using namespace std;
const int n = 4;
int main () {
    string a[4] = {"사과", "딸기", "포도", "배"};
    for(int i = 0; i < (1 << n); i++) {
        cout << i << "\n";
        for(int j = 0; j < n; j++) {
            if(i & (1 << j)) {
                cout << a[j] << " ";
            }
        }
        cout <<"\n";

    }
}