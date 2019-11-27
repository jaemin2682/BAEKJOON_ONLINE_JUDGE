#include <iostream>
#include <string>
#include <stack>
using namespace std;

string str;

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    while(1) {
        getline(cin, str);
        if(str==".") break;

        stack<char> s;
        int size = str.size();
        for(int i=0;i<size;i++) {
            if(!s.empty() && (str[i] == ')' || str[i] == ']')) {
                if(str[i] == ')' && s.top()=='(') s.pop();
                else if(str[i]==']' && s.top()=='[') s.pop();
                else if(str[i]==')' && s.top()!='(') s.push(str[i]);
                else if(str[i]==']' && s.top()!='[') s.push(str[i]);
            }
            else if(str[i] == '(' || str[i] == '[') s.push(str[i]);
            else if(s.empty() && (str[i]==')' || str[i]==']')) s.push(str[i]);
        }

        if(s.empty()) cout << "yes";
        else cout << "no";
        cout << endl;
    }

    return 0;
}
/*
소괄호(), 대괄호()의 짝이 잘 맞아야 하고, 각 소괄호나 대괄호 사이에 있는 소괄호나 대괄호 짝도
짝이 맞아야 한다.
stack을 사용해 여는 소괄호나 대괄호가 있을 시 stack에 push하고, 반대의 짝이 나오면 pop해준다.
&&조건에 empty 먼저 해주는 것이 중요하다. 반대로하면 인덱스오류가 남.
그 결과 스택이 비어있으면 딱 맞았다는 거니까 Yes, 아니라면 No. -> 틀렸습니다.

-> ([)])와 같이, 중간에 닫는괄호가 껴있는 경우는 걸러내지 못했다.
스택 상단이 [인데 )를 만나는 경우나, 상단이 (인데 ]를 만나는 경우를 예외처리해주자. -> 틀렸습니다

->).와 같이, 스택에 들어있는 게 없는데 바로 닫는 괄호가 나올 경우 no가 나올 수 있도록
예외처리를 하였다. -> AC
*/