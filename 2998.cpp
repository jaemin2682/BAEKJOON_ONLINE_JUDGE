#include <iostream>
#include <string>
using namespace std;

string bin;

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin >> bin;
    
    int modsize = bin.size()%3;
    if(modsize!=0)
        for(int i=0;i<3-modsize;i++) bin.insert(bin.begin(), '0');

    int size = bin.size();
    for(int i=0;i<size/3;i++) {
        int octo=0;
        if(bin[i*3] == '1') octo+=4;
        if(bin[i*3+1] == '1') octo+=2;
        if(bin[i*3+2] == '1') octo+=1;
        cout << octo;
    } 

    return 0;
}
/*
문제의 조건처럼 풀어준다. 입력받은 숫자가 3의 배수가 아니면 3의 배수가 되게끔 앞에 0을 더 붙인다.
8진수는 2진수 3자리로 만들 수 있으므로, 3자리씩 쪼개 8진수로 만들어준다.
*/