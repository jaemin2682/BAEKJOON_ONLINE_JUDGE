#include <iostream>
using namespace std;

int n;

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    if(n%2==1) cout << "SK";
    else cout << "CY";
    return 0;
}

//간단한 규칙게임