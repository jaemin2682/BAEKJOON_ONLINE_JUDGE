#include <iostream>
#include <string>
#include <vector>
using namespace std;

string expression;
int ans, rule1, rule2;

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin >> expression >> ans;
    
    int exSize = expression.size();
    vector<int> exp;    //-1을 +, -2를 *로 표현
    for(int i=0;i<exSize;i++) {
        if(expression[i] == '+') exp.push_back(-1);
        else if(expression[i]=='*') exp.push_back(-2);
        else exp.push_back(expression[i]-48);
    }

    int expSize = exp.size(), plus=0; //-1이 +, -2가 *.
    for(int i=0;i<expSize;i++) {    //rule2 답 구하기
        if(exp[i] == -1) plus = -1;
        else if(exp[i] == -2) plus = -2;
        else {
            if(plus==-1) rule2 += exp[i];
            else if(plus==-2) rule2 *= exp[i];
            else rule2 = exp[i];
        }
    }
    int num;   
    for(int i=0;i<exp.size();i++) { //rule 1 전처리(곱셈연산 해놓기)
        if(exp[i]==-2) {
            num = exp[i-1] * exp[i+1];
            exp.erase(exp.begin()+i-1, exp.begin()+i+2);
            exp.insert(exp.begin() + i-1, num);
            i -= 2;
        }
    }
    expSize = exp.size();
    bool isPlus = false;
    for(int i=0;i<expSize;i++) {    //rule1 덧셈 진행
        if(exp[i] == -1) isPlus = true;
        else {
            if(!isPlus) rule1 = exp[i];
            else rule1 += exp[i];
        }
    }

    if(ans == rule1 && ans == rule2) cout << "U";   //출력부
    else if(ans==rule1) cout << "M";
    else if(ans==rule2) cout << "L";
    else cout << "I";

    return 0;
}
/*
어렵다고 할 문제는 아니지만, 아주 쉽게 생각한 것에 비해서는 풀면서 꽤 짜증나는 문제였다.
이쁘게 풀 수 있는지는 모르겠지만, 나는 문자열을 일일히 확인하며 좀 더럽게 푼 것 같다.
시간은 좀 걸렸지만 -> AC
*/