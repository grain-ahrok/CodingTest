#include <bits/stdc++.h>
using namespace std;

int key_pos = 0;
int k, cnt;
char str[9];
int vec[10];

int main () {

    cin >> k;
    for(int i = 0; i < k; i++) {
        cin >> str[i];
    }

    // [1] max 값 구하기
    for(int i = 0; i <= k; i++) {
        vec[i] = 9-i;
    }

    for(int i = 0; i < k; i++) {
        if(str[i] == '>') {
           key_pos++;
           continue;
        } else if(str[i] == '<') {
            cnt ++;
        }

        if(i == k-1 || ( i < k-1 && str[i+1] == '>'))  {
            for(int j = 0; j <= cnt; j++) {
                vec[key_pos + j] = 9 - (key_pos + cnt - j);
            }
            key_pos += cnt;
            cnt = 0;
        } 
    }
    for(int i = 0; i <= k; i++) {
        cout << vec[i];
    }
    cout << "\n";


    // [2] min 값 구하기
    cnt = 0;
    key_pos = 0;
    for(int i = 0; i <= k; i++) {
        vec[i] = i;
    }

    for(int i = 0; i < k; i++) {
        if(str[i] == '<') {
            key_pos++;
            continue;
        } else if(str[i] == '>') {
            cnt++;
        }

        if(i == k-1 || (i < k-1 && str[i+1] == '<')) {
            for(int j = 0; j <= cnt; j++) {
                vec[key_pos+j] = key_pos + cnt - j;
            }
            key_pos += cnt;
            cnt = 0;
        }
    }

    for(int i = 0; i <= k; i++) {
        cout << vec[i];
    }

}