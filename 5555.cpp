#include <iostream>
#include <string>
#include <vector>
using namespace std;

string pattern, str;
int n, ans;

vector<int> getPi(string p) {
    int psize = p.size(), j=0;
    vector<int> pi(psize, 0);
    for(int i=1;i<psize;i++) {
        while(j>0 && p[i] != p[j]) j = pi[j-1];
        if(p[i] == p[j]) pi[i] = ++j;
    }
    return pi;
}

bool kmp(string s, string p) {
    bool Isright = false;
    int ssize = s.size(), psize = p.size(), j=0;
    auto pi = getPi(p);
    for(int i=0;i<ssize;i++) {
        while(j > 0 && s[i] != p[j]) j = pi[j-1];
        if(s[i] == p[j]) {
            if(j == psize-1) {
                j = pi[j];
                Isright = true;
            }
            else j++;
        }
    }
    return Isright;
}

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin >> pattern >> n;
    for(int i=0;i<n;i++) {
        cin >> str;
        str += str;
        ans += kmp(str, pattern);
    }
    cout << ans;
}

/*
패턴이 존재하는지 아닌지 확인하는 문제. 더해서 circular로 찾아야 한다.
나는 그냥 kmp를 사용하되, string을 한번 더 더해줘서 돌렸다.
So easy.
*/