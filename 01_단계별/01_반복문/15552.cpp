
#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 
    

    int tc;
    cin >> tc ;

    int num1, num2;

    for(int i = 0; i < tc; i++) {
        cin >> num1 >> num2;
        cout << num1+num2 << "\n";
    }

    

}