#include <iostream>
#include <string>
#include <vector>
using namespace std;

int L;
string S;

vector<int> GetPi(string p) {
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
    cin >> L >> S;
    auto ans = GetPi(S);
    cout << L - ans[ans.size()-1];
}
/*
KMP알고리즘의 접미사/접두사의 최대길이 배열을 구했다. 
전체 문자열 길이에서 배열의 마지막 값을 빼면 된다.
*.