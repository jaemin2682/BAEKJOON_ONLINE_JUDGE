#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string S;

vector<int> getPi(string p) {
    int Psize = p.size(), j=0;
    vector<int> pi(Psize, 0);
    for(int i=1;i<Psize;i++) {
        while(j > 0 && p[i] != p[j]) j = pi[j-1];
        if(p[i] == p[j]) {
            j++;
            pi[i] = j;
        }
    }
    return pi;
}


int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin >> S;
    int Ssize = S.size();
    int MaxSize = 0;
    for(int i=0;i<Ssize;i++) {
        string s = S.substr(i, Ssize);
        
        auto len = getPi(s);
        for(auto a : len) MaxSize = max(MaxSize, a);
    }

    cout << MaxSize;

    return 0;
}
/*
KMP알고리즘에서 접미사, 접두사가 같은 가장 긴 문자열의 길이를 저장하는 배열을 사용하는 방식을
이용한다. 접두사와 접미사가 겹치는 경우가 이 문제의 조건인 두 번 나오는 가장 긴 문자열이기
때문이다. -> 틀렸습니다

->aaaaafbaaaaf같은 경우, 정답은 5지만 기존 방법은 4를 출력한다. 그렇기 때문에 문자열을
처음부터 하나씩 줄여가면서 위와 같은 작업을 계속 해나가며 최대길이를 찾는다.
*/