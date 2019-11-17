#include <iostream>

using namespace std;

int main() {
    int t;
    cin >> t;
    for(int i=0;i<t;i++) {
        int n, c;
        cin >> n >> c;
        
        if(n%c==0) cout << n/c << endl;
        else cout << n/c+1 << endl;
    }

    return 0;
}