#include <iostream>
#include <string>

using namespace std;

int main() {
    string a, b;
    cin >> a >> b;
    for(int i=0;i<a.size();i++)
        if(a[i]=='6') a[i] = '5';
    for(int i=0;i<b.size();i++)
        if(b[i]=='6') b[i] = '5';
    cout << stoi(a) + stoi(b)<< " ";

    for(int i=0;i<a.size();i++)
        if(a[i]=='5') a[i] = '6';
    for(int i=0;i<b.size();i++)
        if(b[i]=='5') b[i] = '6';
    cout << stoi(a) + stoi(b);

    return 0;
}
/*
숫자를 바꾸기 용이하게 string으로 입력받고, 덧셈연산은 int로 만들어 수행하였다.
*/