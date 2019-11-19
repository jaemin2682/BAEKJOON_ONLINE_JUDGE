#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    long long price=0;
    cin >> n;
    vector<int> arr(n);
    for(int i=0;i<n;i++) {
        cin >> arr[i];
        price += arr[i];
    }
    int size = arr.size();
    sort(arr.begin(), arr.end(), greater<int>());

    while(arr.size() >= 3) {
        price -= arr[2];
        arr.erase(arr.begin(), arr.begin() + 3);
    }

    cout << price;

    return 0;
}