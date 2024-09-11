#include <bits/stdc++.h>
using namespace std;

int treeM[26][2] = {{0,},};
int N;

// 전위순회
void preorder(int root) {
    cout << (char)(root+'A');
    if(treeM[root][0] != -1) preorder(treeM[root][0]);
    if(treeM[root][1] != -1) preorder(treeM[root][1]);
}

// 중위순회
void inorder(int root) {
    if(treeM[root][0] != -1) inorder(treeM[root][0]);
    cout << (char)(root+'A');
    if(treeM[root][1] != -1) inorder(treeM[root][1]);
}

// 후위순회
void postorder(int root) {
    if(treeM[root][0] != -1) postorder(treeM[root][0]);
    if(treeM[root][1] != -1) postorder(treeM[root][1]);
    cout << (char)(root+'A');
}


int main() {
    cin >> N;
    char tmp1, tmp2;
    for(int i = 0; i < N; i++) {
        cin >> tmp1;
        for(int j = 0; j < 2; j++) {
            cin >> tmp2;
            if(tmp2 != '.') {
                treeM[tmp1-'A'][j] = tmp2-'A';
            } else {
                treeM[tmp1-'A'][j] = -1;
            }
        }
    }

    preorder(0);
    cout << "\n";
    inorder(0);
    cout << "\n";
    postorder(0);

}