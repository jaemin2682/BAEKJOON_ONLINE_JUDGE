#include <iostream>
using namespace std;

long long n;

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    if(n%7==0 || n%7==2) cout << "CY";
    else cout << "SK";
    return 0;
}