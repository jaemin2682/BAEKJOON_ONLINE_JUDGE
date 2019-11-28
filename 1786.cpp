#include <iostream>
#include <string>
#include <vector>
using namespace std;

string T, P;

vector<int> getPi(string p) {
    int psize = p.size(), j=0;
    vector<int> pi(psize, 0);
    for(int i=1;i<psize;i++) {
        while(j > 0 && p[i] != p[j]) j = pi[j-1];
        if(p[i] == p[j]) {
            j++;
            pi[i] = j;
        }
    }
    return pi;
}

vector<int> kmp(string s, string p) {
    int Ssize = s.size(), Psize = p.size(), j=0;
    auto pi = getPi(p);
    vector<int> ans;
    for(int i=0;i<Ssize;i++) {
        while(j > 0 && s[i] != p[j]) j = pi[j-1];
        if(s[i] == p[j]) {
            if(j == Psize-1) {
                j = pi[j];
                ans.push_back(i - Psize + 1);
            }
            else j++;
        }
    }
    return ans;
}

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    getline(cin, T);
    getline(cin, P);

    auto res = kmp(T, P);
    cout << res.size() << endl;
    for(int i=0;i<res.size();i++) cout << res[i]+1 << " ";

    return 0;
}