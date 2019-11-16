#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    int sum = 0;
    for(int i=0;i<n;i++) {
        int c, k;
        cin >> c >> k;
        sum += c*k;
    }
    cout << sum;


    return 0;
}