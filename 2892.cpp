#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int n;
string num;

int toDec(string s) {
    int idx = s.size()-1, dec=0, factor=1;
    while(idx >= 0) {
        int num;
        if(s[idx]=='A' || s[idx]=='a') num = 10;
        else if(s[idx]=='B' || s[idx]=='b') num=11;
        else if(s[idx]=='C' || s[idx]=='c') num=12;
        else if(s[idx]=='D' || s[idx]=='d') num=13;
        else if(s[idx]=='E' || s[idx]=='e') num=14;
        else if(s[idx]=='F' || s[idx]=='f') num=15;
        else num = s[idx]-48;
        dec += factor*num;
        factor*=16;
        idx--;
    }
    return dec;
}

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i=0;i<n;i++) {
        cin >> num;
        if(toDec(num) >= 64) cout << '-';
        else cout << '.';
    }
    return 0;
}
/*
어려운 문제는 아닌데 문제가 이해가 안가서 되게 오래 걸렸다.
0~9 XOR a~z : 40 ~ 5f
0~9 XOR ' ' : 10 ~ 19
0~9 XOR '.' : 16 ~ 1f
이 조합을 전부 돌려봐서 값의 범위를 구해보았다. 결국 입력으로 들어오는 값은
암호화가 된 16진수 수이기 때문에, String으로 받아서 10진수로 바꾸어 주고, 
64(0x40)보다 같거나 큰 수는 문자, 아닌 경우는 공백이나 온점이다.
*/