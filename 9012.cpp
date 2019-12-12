#include <iostream>
#include <string>
#include <stack>
using namespace std;

int T;
string str;

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0); 
    cin >> T;
    for(int test_case=0;test_case<T;test_case++) {
        cin >> str;
        stack<char> s;
        int strSize = str.size(), stack=0;
        bool isVSP = true;
        for(int i=strSize-1;i>=0;i--) s.push(str[i]); //뒤부터 넣는다 
        for(int i=0;i<strSize;i++) {
            if(s.top() == '(') stack++; //'('면 ++
            else stack--;   //')'면 --
            s.pop();
            if(stack<0) {   //열지도 않았는데 닫히는 경우는 무조건 not VSP
                isVSP = false;
                break;
            }
        }
        if(stack != 0) isVSP = false;   //'('와 ')'의 개수가 같지 않으면 not VSP

        if(isVSP) cout << "YES" << '\n';
        else cout << "NO" << '\n';
    }
    return 0;
}
// 기본적인 스택문제였다.