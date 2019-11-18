#include <iostream>

using namespace std;
/*
1 : CY
2 : SK
3 : CY
4 : SK
5 : CY...
*/


int main() {
    int n;
    cin >> n;
    
    if(n%2 == 0) cout << "SK";
    else cout << "CY";
    
    return 0;
}