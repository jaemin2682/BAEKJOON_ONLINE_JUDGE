#include <iostream>
#include <string>
using namespace std;

int k;
string s1, s2;

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin >> k;
    cin.ignore();
    for(int i=1;i<=k;i++) {
        getline(cin, s1);
        getline(cin, s2);
        int s1Size=s1.size(), s2Size = s2.size();
        for(int j=0;j<s1Size;j++) { //(, )로 통일, ,로 통일, 소문자로 통일
            if(s1[j] == '{' || s1[j] == '[') s1[j] = '(';
            else if(s1[j] == '}' || s1[j] == ']') s1[j] = ')';
            else if(s1[j] == ';') s1[j] = ',';
            else if(s1[j] >= 'A' && s1[j] <= 'Z') s1[j] +=32;
        }
        for(int j=0;j<s2Size;j++) { //(, )로 통일, ,로 통일, 소문자로 통일
            if(s2[j] == '{' || s2[j] == '[') s2[j] = '(';
            else if(s2[j] == '}' || s2[j] == ']') s2[j] = ')';
            else if(s2[j] == ';') s2[j] = ',';
            else if(s2[j] >= 'A' && s2[j] <= 'Z') s2[j] +=32;
        }

        int tem;
        for(int j=0;j<s1Size;j++) { //맨앞, 맨뒤 공백 제거
            if(s1[j] != ' ') {
                tem = j;
                break;
            }
        }
        s1.erase(s1.begin(), s1.begin()+tem);
        for(int j=0;j<s2Size;j++) {
            if(s2[j] != ' ') {
                tem = j;
                break;
            }
        }
        s2.erase(s2.begin(), s2.begin()+tem);

        for(int j=0;j<s1.size()-1;j++) {    //두 개 이상의 공백은 하나로
            if(s1[j] == ' ' && s1[j+1] == ' ') {
                s1.erase(s1.begin() + j);
                j--;
            }
        }
        for(int j=0;j<s2.size()-1;j++) {
            if(s2[j] == ' ' && s2[j+1] == ' ') {
                s2.erase(s2.begin() + j);
                j--;
            }
        }
        bool IsNearCom = false;
        for(int j=0;j<s1.size();j++) {  //특수문자 주변 공백 지우기
            if(s1[j] == '(' || s1[j] == ')' || s1[j] == '.' || s1[j] == ',' || s1[j] == ':')
                IsNearCom = true;
            else if((s1[j] >= 'a' && s1[j] <= 'z') || (s1[j] >= '0' && s1[j] <= '9'))
                IsNearCom = false;
            else if(s1[j] == ' ' && IsNearCom) {
                s1.erase(s1.begin() + j);
                j--;
            }
        }
        IsNearCom = false;
        for(int j=0;j<s2.size();j++) {  //특수문자 주변 공백 지우기
            if(s2[j] == '(' || s2[j] == ')' || s2[j] == '.' || s2[j] == ',' || s2[j] == ':')
                IsNearCom = true;
            else if((s2[j] >= 'a' && s2[j] <= 'z') || (s2[j] >= '0' && s2[j] <= '9'))
                IsNearCom = false;
            else if(s2[j] == ' ' && IsNearCom) {
                s2.erase(s2.begin() + j);
                j--;
            }
        }
        IsNearCom = false;
        for(int j=s1.size()-1;j>=0;j--) {  //특수문자 주변 공백 지우기(반대편)
            if(s1[j] == '(' || s1[j] == ')' || s1[j] == '.' || s1[j] == ',' || s1[j] == ':')
                IsNearCom = true;
            else if((s1[j] >= 'a' && s1[j] <= 'z') || (s1[j] >= '0' && s1[j] <= '9'))
                IsNearCom = false;
            else if(s1[j] == ' ' && IsNearCom) {
                s1.erase(s1.begin() + j);
                j++;
            }
        }
        IsNearCom = false;
        for(int j=s2.size()-1;j>=0;j--) {  //특수문자 주변 공백 지우기
            if(s2[j] == '(' || s2[j] == ')' || s2[j] == '.' || s2[j] == ',' || s2[j] == ':')
                IsNearCom = true;
            else if((s2[j] >= 'a' && s2[j] <= 'z') || (s2[j] >= '0' && s2[j] <= '9'))
                IsNearCom = false;
            else if(s2[j] == ' ' && IsNearCom) {
                s2.erase(s2.begin() + j);
                j++;
            }
        }

        cout << "Data Set " << i << ": ";
        if(s1 == s2) cout << "equal" << endl;
        else cout << "not equal" << endl;
        cout << endl;
    }
    
    return 0;
}
/*
출력 형식이 잘못된 오류를 직접 구현해보는 재미있는 문제다. 규칙을 만족하게 코딩해보자.
1. 알파벳 대, 소문자 구별 안함
2. 공백의 유무는 다르면 안된다. 하지만 공백이 있다면 공백의 수는 구별하지 않는다.
3. 맨 앞 / 맨 뒤의 공백은 상관없다.
4. 특수 부호의 바로 앞 / 뒤의 공백은 구별 X
5. 여는 괄호 / 닫는 괄호끼리는 종류 구별 X
6. 쉼표","와 세미콜론";"은 구별 X

*/
