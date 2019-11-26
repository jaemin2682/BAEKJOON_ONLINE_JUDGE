#include <iostream>
#include <algorithm>

using namespace std;

int L, a, b, c, d;

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0);
    cin >> L >> a >> b >> c >> d;

    int dif = a/c + 1;
    int dif1 = b/d + 1; 
    if(a%c == 0) dif--;
    if(b%d == 0) dif1--;
    cout << L - max(dif, dif1);

    return 0;
}
//간단한 계산문제이다. 딱 나눠질 때와 그렇지 않을때만 나누어주면 된다.