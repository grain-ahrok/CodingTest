#include <bits/stdc++.h>
using namespace std;

vector<string> split(string input, string delimeter) {
    vector<string> ret;
    long long pos = 0;
    string token = "";
    while((pos = input.find(delimeter)) != string::npos) {
        token = input.substr(0, pos);
        ret.push_back(token);
        input.erase(0, pos + delimeter.length());
    }
    return ret;
}

int main() {
    string str = "안녕하세요 제 이름은 최아록이고 정보보안 전문가가 되는 것이 꿈입니다.";
    vector<string> strs = split(str, " ");
    for(string a : strs) cout << a << endl;
}