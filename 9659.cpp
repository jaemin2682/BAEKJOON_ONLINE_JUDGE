#include <iostream>
using namespace std;

long long n;

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    if(n%2==1) cout << "SK";
    else cout << "CY";

    return 0;
}
/* 상근, 창영. 돌 1개 or 3개, 상근이가 먼저 시작, 마지막 돌 가져가는 사람 승리
1개 : 상근(1개) -> 상근
2개 : 상근(1개), 창영(1개) -> 창영
3개 : 상근(3개) -> 상근
4개 : 상근(1개) -> 창영(3개) -> 창영
5개 : 상근(1개) -> 창영(3개) -> 상근(1개) -> 상근
6개 : 상근 ... -> 창영
*/