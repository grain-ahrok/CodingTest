#include <bits/stdc++.h>
using namespace std;

int main() {
    
    // "포케몬 이름" : "index"
    map<string, int> imap;
    // 포케몬 이름 리스트
    vector<string> slist;
    // 결과 출력
    vector<string> result;

    string str;
    int N, M = 0; 
    cin >> N >> M;
    

    for(int i = 1; i <= N; i++) {
        cin >> str;
        imap.insert(make_pair(str, i));
        slist.push_back(str);
    }

    for(int i = 0; i < M; i++) {
        cin >> str;
        if (str[0] >= 65 && str[0] <= 90) {
            result.push_back(to_string(imap[str]));
        } else {
            result.push_back(slist[stoi(str)-1]);
        }
    }

    for(int i = 0; i < M; i++) {
        cout << result[i] << '\n';
    }
    return 0;
}


