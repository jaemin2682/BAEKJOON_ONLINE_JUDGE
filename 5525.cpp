#include <iostream>
#include <string>
#include <vector>
using namespace std;

int N, M, ans;
string S, P;

vector<int> GetPi(string p) {
    int psize = p.size(), j=0;
    vector<int> pi(psize, 0);
    for(int i=1;i<psize;i++) {
        while(j > 0 && p[i] != p[j])
            j = pi[j-1];
        if(p[i] == p[j]) {
            j++;
            pi[i] = j;
        }
    }
    return pi;
}

void kmp(string s, string p) {
    auto pi = GetPi(p);
    int Ssize = s.size(), Psize = p.size(), j=0;
    for(int i=0;i<Ssize;i++) {
        while(j > 0 && s[i] != p[j])
            j = pi[j-1];
        if(s[i] == p[j]) {
            if(j == Psize-1) {
                ans++;
                j = pi[j];
            }
            else j++;
        }
    }
}

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M;
    cin >> S;

    for(int i=0;i<N*2+1;i++) {
        if(i%2==0) P+='I';
        else P+='O';
    }

    kmp(S, P);
    cout << ans;
   
    return 0;
}
/*
KMP를 이용했다. 접두사와 접미사가 최대한 겹치는 개수를 구하는 함수와
kmp함수(겹치는 개수만큼 점프할 수 있는 함수)를 구현해 풀었다.
*/