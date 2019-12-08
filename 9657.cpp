#include <iostream>
using namespace std;

int n;

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    if(n%7==0 || n%7==2) cout << "CY";
    else cout << "SK";
    return 0;
}
/* 돌 : 1 / 3 / 4
0 : 창영
1 : 상근
2 : 창영
3 : 상근
4 : 상근
5 : 상근
6 : 상근
7 : 창영(1411)
8 : 상근(11411)
9 : 창영(111411)
C S C S S S S 의 반복이 된다.
*/