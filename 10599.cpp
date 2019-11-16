#include <iostream>
#include <math.h>

using namespace std;

int main() {
    while(1) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        if(a==0 && b==0 && c==0 && d==0) return 0;
        cout << abs(b-c) << " " << abs(a-d) << endl;
    }
}