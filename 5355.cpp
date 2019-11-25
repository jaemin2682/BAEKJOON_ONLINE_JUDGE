#include <iostream>
#include <string>

using namespace std;

int main() {
    int t;
    cin >> t;
    for(int i=0;i<t;i++) {
        double num;
        string str;
        cin >> num;
        getline(cin, str);
        for(int j=0;j<str.size();j++) {
            if(str[j] == '@') num*=3;
            else if(str[j] == '%') num+=5;
            else if(str[j] == '#') num-=7;
        }
        printf("%.2f\n", num);
    }

    return 0;
}
/*
간단한 문자열 처리 문제
*/