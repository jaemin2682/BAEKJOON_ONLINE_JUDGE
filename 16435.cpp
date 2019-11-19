#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, l;
    cin >> n >> l;
    vector<int> fruit(n);
    for(int i=0;i<n;i++)
        cin >> fruit[i];
    sort(fruit.begin(), fruit.end());
    for(int i=0;i<fruit.size();i++) {
        if(fruit[i] <= l) l++;
    }
    cout << l;

    return 0;
}