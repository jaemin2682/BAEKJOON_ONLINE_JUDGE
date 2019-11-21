#include <iostream>

using namespace std;

int main() {
    int num;
    cin >> num;
    if(num==1) cout << 65;
    else if(num==2) cout << 17;
    else if(num==3) cout << 4;
    else if(num==4) cout << 4;
    else cout << 64;

    return 0;
}

/*
백준 7제 난대 문제 중 하나.
1. 스타트링크 사무실에 있는 가장 큰 TV는 X인치다.
2. 스타트링크 사무실 벽에 붙어있는 포스터는 X장이다.
3. 스타트링크 사무실 안에 있는 iPad의 개수는 X개이다. (모든 iPad 시리즈 전부 포함)
4. 스타트링크 사무실 안에 있는 모니터의 개수는 X개이다.
5. 스타트링크 사무실에 있는 게임용 컴퓨터의 RAM의 총 용량은 X GB이다.

*/