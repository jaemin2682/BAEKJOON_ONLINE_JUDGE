#include <iostream>
#include <string>

using namespace std;

int main() {
    string me, doctor;
    cin >> me >> doctor;
    if(me.size() >= doctor.size()) cout << "go";
    else cout << "no";

    return 0;
}

/*
둘째 줄의 입력이 첫째 줄의 입력보다 작거나 같으면 go이다.
*/