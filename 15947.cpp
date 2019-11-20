#include <iostream>

using namespace std;

int main() {
    int n, cnt, value=1;
    cin >> n;

    while(n>14) {
        n -= 14;
        value++;
    }
    if(n==1 || n==13) cout << "baby";
    else if (n==2 || n==14) cout << "sukhwan";
    else if(n==5) cout << "very";
    else if(n==6) cout << "cute";
    else if(n==9) cout << "in";
    else if(n==10) cout << "bed";
    else if(n==3 || n==7 || n==11) {
        if(value+1 < 5) {
            cout << "tu";
            for(int i=0;i<value+1;i++) cout <<"ru";
        }
        else {
            cout << "tu+ru*" << value+1;
        }
    }
    else {
        if(value < 5) {
            cout << "tu";
            for(int i=0;i<value;i++) cout << "ru";
        }
        else {
            cout << "tu+ru*" << value;
        }
    }
    return 0;
}

/*
4, 4, 4, 2.  한 곡당 14단어이다. (1~14)
1번째는 baby, 2번째는 sukhwan
5번째는 very, 6번째는 cute
9번째는 in, 10번째는 bed
13번째는 baby, 14번째는 sukhwan. 은 고정이다.

3, 7, 11번째는 turu + n번째 * ru, 4, 8, 12번째는 tu + n번째 * ru

출력할 단어가 turu...ru이면 ru가 5번 이상 반복되면 "tu+ru*k"로 출력한다.

*/