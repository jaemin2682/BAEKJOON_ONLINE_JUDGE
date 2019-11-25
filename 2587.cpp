#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    vector<int> arr(5);
    int sum = 0;
    for(int i=0;i<5;i++) {
        cin >> arr[i];
        sum += arr[i];
    }
    sort(arr.begin(), arr.end());

    cout << sum/5 << endl << arr[2];

    return 0;
}
/*
평균과 중앙값을 구한다.
*/