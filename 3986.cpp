#include <iostream>
#include <stack>
#include <string>

using namespace std;

int n, res;
string str;

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i=0;i<n;i++) {  
        cin >> str; 
        stack<char> s;

        int size = str.size();
        for(int j=0;j<size;j++) {
            if(!s.empty() && s.top() == str[j]) s.pop();
            else s.push(str[j]);
        }

        if(s.empty()) res++;
    }

    cout << res;

    return 0;
}
/*
문제가 조금 난해해서 이해하는데 좀 걸렸다. 괄호를 확인하는 것과 같이 한 문자가 열고
다른 문자가 닫을 때, 그 사이에 닫히지 않은 다른 문자가 있으면 안 되는 문제이다.
내가 말하면서도 이게 무슨 말인지 싶다. 구현해보자
stack을 활용한다. 문자를 훑으며 stack에 넣고, stack의 최상단과 다음 문자가 같으면 pop
*/