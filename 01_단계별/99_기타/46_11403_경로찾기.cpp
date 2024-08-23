#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    int nmap[101][101] = {{0,},};
    int visited[101][101] = {{0,},};

    cin >> N;

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            cin >> nmap[i][j];
        }
    }

    vector<int> v;
    int cur;
    
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            if(nmap[i][j]){
                v.push_back(j);
                visited[i][j] = 1;
            }
        }

        while(v.size()){
            
            cur = v.back();
            v.pop_back();
            

            for(int j = 0; j < N; j++) {

                if(nmap[cur][j] && visited[i][j] != 1) {
                    v.push_back(j);
                    visited[i][j] = 1;

                }
            }
        }
    }

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            cout << visited[i][j] << " ";
        }
        cout << "\n";
    }



}
