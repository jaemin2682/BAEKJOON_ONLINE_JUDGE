#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> list;
    for(int i=0;i<n;i++) {
        int num;
        cin>>num;
        list.push_back(num);
    }
    sort(list.begin(), list.end());
    for(int i=0;i<list.size();i++) cout << list[i] << " ";

    return 0;
}