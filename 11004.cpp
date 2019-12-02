#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, k, num;
vector<int> arr;

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k;
    for(int i=0;i<n;i++) {
        cin >> num;
        arr.push_back(num);
    }
    sort(arr.begin(), arr.end());

    cout << arr[k-1];

    return 0;
}
