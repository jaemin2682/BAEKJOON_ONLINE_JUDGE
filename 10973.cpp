#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i=0;i<n;i++) scanf("%d", &arr[i]);
    
    int idx1=0, idx2=n-1;
    for(idx1 = n-1;idx1 > 0 && arr[idx1-1] < arr[idx1];idx1--) {}
    
    if(idx1 == 0) {
        cout << -1;
        return 0;
    }

    for(idx2 = n-1;idx2>=idx1 && arr[idx2] > arr[idx1-1];idx2--) {}

    swap(arr[idx1-1], arr[idx2]);
    idx2 = n-1;

    while(idx1 < idx2) {
        swap(arr[idx1], arr[idx2]);
        idx1++;
        idx2--;
    }

    for(int i=0;i<n;i++) cout << arr[i] << " ";

    return 0;
}
/*
prev_permutation 함수가 있지만, 구현해 보았다. 조금 더 익숙해질 필요가 있어 보인다.

*/