#include <iostream>

using namespace std;

int main() {
    int p;
    cin >> p;
    for(int i=0;i<p;i++) {
        int n;
        double d, a, b, f;
        cin >> n >> d >> a >> b >> f;
        cout << n << " " << d/(a+b)*f << endl;
    }
    
    return 0;
}