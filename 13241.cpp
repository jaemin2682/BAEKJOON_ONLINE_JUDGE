#include <iostream>

using namespace std;

int main() {
    long long a, b;
    cin >> a >> b;
    long long mul = a*b;
    if(a < b) swap(a, b);
    while(b!=0) {
        long long temp = a%b;
        a = b;
        b = temp;
    }
    cout << mul / a;

    return 0;
}