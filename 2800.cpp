#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <set>
using namespace std;

string equals;
stack<int> s;
vector<pair<int, int>> v;
set<string> list;

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin >> equals;
    int equalSize = equals.size();
    
    for(int i=0;i<equalSize;i++) {
        if(equals[i] == '(') s.push(i);
        else if(equals[i] == ')') {
            int num = s.top();
            s.pop();
            v.push_back({num, i});
        }
    }
    int vSize = v.size();
    int bits = (1 << vSize) - 1;    //bits = 2^vSize - 1
    while(bits>0) {
        string x = equals;
        for(int i=0;i<vSize;i++)    //비트연산으로 체크해서 해당인덱스를 공백문자로 바꿈
            if(bits&(1<<i))
                x[v[i].first] = x[v[i].second] = ' ';
        string complete;
        for(int i=0;i<equalSize;i++)    //공백문자를 빼준다.
            if(x[i] != ' ') complete += x[i];
        list.insert(complete);   //정렬/중복제거를 위해 저장
        bits--;
    }
    set<string>::iterator iter;
    for(iter = list.begin();iter!=list.end();iter++)
        cout << *iter << '\n';

    return 0;
}
/*
스택을 이용하여 괄호쌍의 인덱스들을 모두 모은다.(n가지)
각 괄호쌍은 출력한다/출력안한다의 2가지 경우로 총 2^n - 1가지 경우가 나온다(모두출력 제외)
비트연산으로 각 인덱스를 체크하여 문자열들을 모아주어, 사전식으로 정렬해 출력한다.
*/