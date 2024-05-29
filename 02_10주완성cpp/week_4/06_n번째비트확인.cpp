#include <bits/stdc++.h>
using namespace std;

int main() {
    int S = 18;
    int idx = 3;   
    bool isOn = (S >> idx) & 1;
    cout << isOn;
}