#include <iostream>

using namespace std;

int main() {
    int t;
    cin >> t;
    for(int i=0;i<t;i++) {
        int a, b;
        cin >> a >> b;
        int mul = a/b;
        cout << mul*mul << endl;
    }
    
    return 0;
}