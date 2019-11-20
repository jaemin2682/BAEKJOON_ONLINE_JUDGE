#include <iostream>
#include <vector>

using namespace std;

int main() {
    bool good = true;
    int tem = -1000001;
    while(1) {
        int num;
        if(cin.eof()) break;
        cin >> num;
        if(num < tem) good = false;
        tem = num;
    }

    if(good) cout << "Good";
    else cout << "Bad";

    return 0;
}
/*
주어진 정수가 오름차순인지 판별하기.
전값을 기억해서 한번이라도 다음값이 전값보다 작다면 Bad.
*/