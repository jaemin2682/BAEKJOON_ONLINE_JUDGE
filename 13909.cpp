#include <iostream>
#include <math.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    cout << (int)sqrt(n);
    

    return 0;
}
/*
n이 21억이 될 수도 있으니, 하나씩 열고 닫는 것은 안해봐도 오답이다.
처음에 모든 창문은 닫혀있다. 각 수의 약수의 수를 알면 풀 수 있다.
하지만 이것도 엄청 느릴거같다.
-> 열려 있는 창문의 수를 구해야한다.
O > OX > OXX > OXXO > OXXOX > OXXOXX > OXXOXXX > OXXOXXXX > OXXOXXXXO
내 직관이 말하고 있다. 3, 9, 16, 25.. 제곱수마다 열려 있는 창문의 수가 1씩 늘어나는 것 같다.

*/