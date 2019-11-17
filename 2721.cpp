#include <iostream>

using namespace std;

int main() {
    int t;
    cin >> t;
    for(int i=0;i<t;i++) {
        int n, sum=0, t = 1;
        cin >> n;
        for(int j=1;j<=n;j++) {
            t += j+1;
            sum += j * t;
        }
        cout << sum << endl;
    }

    return 0;
}