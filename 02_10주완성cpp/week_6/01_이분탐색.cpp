#include <bits/stdc++.h>
using namespace std;
// 정렬된 배열에서 지정한 숫자가 존재하는 지 확인하는 로직.

int binarySearch(const vector<int>& arr, int target) {
    int left = 0;
    int right = arr.size()-1;
    int mid;

    while(left <= right) {
        mid = (left+right)/2;

        if(arr[mid] < target) {
            left = mid+1;
        } else if(arr[mid] > target) {
            right = mid-1;
        } else {
            return mid;
        }
    }
    return -1;
}

int main() {
    vector<int> arr = {1, 3, 6, 9, 10, 21, 22, 30};
    int target = 6;
    int result = binarySearch(arr, target);

    if(result != -1) {
        cout << "Target found at index: " << result << "\n";
    } else {
        cout << "Target not found in the array \n";
    }

    return 0;
}
