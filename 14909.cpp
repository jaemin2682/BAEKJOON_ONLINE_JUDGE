#include <iostream>
#include <string>

using namespace std;

int main() {
    string str;
    getline(cin, str);
    int cnt=0, size=0;
    for(int i=0;i<str.size()-1;i++) {
        if(str[i]=='-' || (str[i]==' ' && str[i+1]=='0')) cnt++;
        if(str[i]==' ') size++;
    }
    if(str.size() == 1 && str[0] == '0') cnt=1;
    cout << size+1 - cnt;

    return 0;
}