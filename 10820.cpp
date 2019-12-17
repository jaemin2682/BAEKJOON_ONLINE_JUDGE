#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <set>
#include <map>
using namespace std;

int n;

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    while(1) {
        string str;
        getline(cin, str);
        if(cin.eof()) break;

        int lower=0, upper=0, number=0, space=0;
        int strSize = str.size();
        for(int i=0;i<strSize;i++) {
            if(str[i]>='a' && str[i]<='z') lower++;
            else if(str[i]>='A' && str[i]<='Z') upper++;
            else if(str[i]>='0' && str[i]<='9') number++;
            else if(str[i] == ' ') space++;
        }
        cout << lower << ' ' << upper << ' ' << number << ' ' << space << '\n';
    }
    return 0;
}
/*
그냥 문자열을 조회하면 되는 문제였다.
*/