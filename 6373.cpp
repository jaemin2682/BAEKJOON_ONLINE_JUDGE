#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

string multiply(string s, int a) {  //s에 a를 곱했을 때의 문자열 출력
    int size = s.size(), factor=0, zerocnt=0;
    string ans;
    bool isBig = false;
    for(int i = size-1;i>=0;i--) {
        int tem = (s[i]-48)*a+factor;
        if(i==0 && tem >= 10) isBig = true;
        factor = (tem - tem%10)/10;
        ans.insert(0, to_string(tem%10));
    }
    if(isBig) ans.insert(0, to_string(factor));
    return ans;
}

vector<int> getpi(string p) {
    int p_size = p.size(), j=0;
    vector<int> pi(p_size, 0);
    for(int i=1;i<p_size;i++) {
        while(j>0&&p[i]!=p[j]) j = pi[j-1];
        if(p[i] == p[j]) pi[i] = ++j;
    }
    return pi;
}

bool kmp(string s, string p) {
    int s_size = s.size(), p_size=p.size(), j=0;
    bool isIn = false;
    auto pi = getpi(p);
    for(int i=0;i<s_size;i++) {
        while(j>0&&s[i]!=p[j]) j = pi[j-1];
        if(s[i] == p[j]) {
            if(j == p_size-1) {
                isIn = true;
                break;
            }
            else j++;
        }
    }
    return isIn;
}


int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    while(1) {
        string str;
        cin >> str;
        if(cin.eof()) break;
        
        int size = str.size();
        bool iscycle = true;
        for(int i=2;i<=size;i++) {
            string multi_str = multiply(str, i);    //i를 곱한 string을 만듬
            multi_str += multi_str; //2개를 이어붙임.
            if(!kmp(multi_str, str)) {  //포함하는 문자열인지 확인
                iscycle = false;
                break;
            }
        }
        if(iscycle) cout << str << " is cyclic" << endl;
        else cout << str << " is not cyclic" << endl;
    }

	return 0;
}
/*
비트 범위가 60까지이기 때문에, long long을 이용해도 숫자를 이용한 곱은 할 수 없다.
따라서, 받은 문자열을 곱해줄 함수를 따로 만든다.
그리고 곱한 결과의 문자열이 처음 문자열과 cyclic을 이루는지 알아야 한다.
나는 곱한 결과의 문자열 두 개를 이어 붙여, kmp 알고리즘을 사용해 원래 문자열이 그 문자열에
존재하는지 확인해 볼 것이다. -> AC
*/