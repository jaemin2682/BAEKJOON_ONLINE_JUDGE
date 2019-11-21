#include <iostream>

using namespace std;

int main() {
    int a, b, c, d, p, m, n;
    cin >> a >> b >> c >> d >> p >> m >> n;

    int pcnt=0, mcnt=0, ncnt=0;

    if(p%(a+b) > 0 && p%(a+b) <= a) pcnt++;
    if(p%(c+d) > 0 && p%(c+d) <= c) pcnt++;

    if(m%(a+b) > 0 && m%(a+b) <= a) mcnt++;
    if(m%(c+d) > 0 && m%(c+d) <= c) mcnt++;

    if(n%(a+b) > 0 && n%(a+b) <= a) ncnt++;
    if(n%(c+d) > 0 && n%(c+d) <= c) ncnt++;

    cout << pcnt << endl << mcnt << endl << ncnt;

    return 0;
}

/*
수학식 문제. 공격시간과 비공격시간을 더한 값의 나머지가 1~공격시간이 나와야 한다.
*/