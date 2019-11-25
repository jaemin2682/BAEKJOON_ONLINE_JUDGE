#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    while(1) {
        string str;
        getline(cin, str);
        if(str == "END") break;
        reverse(str.begin(), str.end());
        cout << str << endl;
    }
    return 0;
}
/*
간편하게 algorithm에있는 reverse 메소드를 사용하였다.
*/