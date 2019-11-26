#include <iostream>

using namespace std;

int x1, x2, x3, y1, y2, y3;

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin >> x1 >> y1 >> x2 >>y2 >> x3 >> y3;

    if(x1==x2) cout << x3 << " ";
    else if(x1==x3) cout << x2 << " ";
    else if(x2==x3) cout << x1 << " ";

    if(y1==y2) cout << y3;
    else if(y2==y3) cout << y1;
    else if(y1==y3) cout << y2;

    return 0;
}
/*
축에 평행한 직사각형의 꼭지점은 반드시 같은 x좌표를 가지는 점과 y표를 가지는 점이 존재한다.
따라서, x좌표와 y좌표가 무조건 짝수개가 나와야 하므로, 홀수인 좌표가 나머지 한 점의 좌표이다.
*/