#include <bits/stdc++.h>
using namespace std;

int main() {

    string T, P;
    getline(std::cin, T);
    getline(std::cin, P);

    int n = T.length();
    int m = P.length();
    int pi[1000001] = {0,};
    int j = 0;

    // P 전처리 과정
    for (int i = 1; i < m; i++) {
		while ((j > 0) && (P[i] != P[j])) {
			j = pi[j - 1];
		}
		if (P[i] == P[j]) {
			j++;
			pi[i] = j;
		}
	}

    // for(int i = 1; i < m+1; i++) {
    //     cout << P.substr(0, i) <<  " : " << pi[i-1] << "\n";
    // }

    
    int cnt = 0;
    j = 0;
    vector<int> res;

    for(int i = 0; i < n; i++) {
        while(j > 0 && T[i] != P[j]) {
            j = pi[j-1];
        }

        if(T[i] == P[j]) {
            if(j == m-1) {
                cnt ++; 
                res.push_back(i-m+2);
                j = pi[j];
            } else {
                j++;
            }
        }
    }

    cout << cnt << "\n";
    for(int i : res) {
        cout << i << " ";
    }
}


