#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int a, b, c, x, y;
    cin >> a >> b >> c >> x >> y;

    int banbanMin = min(x, y), sum=0;
    if(a+b > 2*c) sum = 2*c*banbanMin;
    else sum = (a+b)*banbanMin;
    
    int tem1 = (x-banbanMin)*a + (y-banbanMin)*b;   //반반 사고 따로 살 때
    int tem2 = (max(x, y) - banbanMin) * 2*c;  //따로 사야하지만 반반이 더싸서 반반 살 때
    sum += min(tem1, tem2);
    cout << sum;

    return 0;
}