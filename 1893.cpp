#include <iostream>
#include <string>
#include <vector>
using namespace std;

int N;
string A, W, S;

vector<int> getPi(string p) {
    int psize=p.size(), j=0;
    vector<int> pi(psize, 0);
    for(int i=1;i<psize;i++) {
        while(j>0 && p[i] != p[j]) j = pi[j-1];
        if(p[i] == p[j]) pi[i] = ++j;
    }
    return pi;
}

bool kmp(string s, string p) {
    int ssize = s.size(), psize=p.size(), j=0, cnt=0;
    auto pi = getPi(p);
    for(int i=0;i<ssize;i++) {
        while(j>0 && s[i]!=p[j]) j = pi[j-1];
        if(s[i] == p[j]) {
            if(j==psize-1) {
                cnt++;
                j=pi[j];
            }
            else j++;
        }
    }
    if(cnt==1) return true;
    else return false;
}

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    for(int i=0;i<N;i++) {
        cin >> A >> W >> S;
        int Asize=A.size(), Wsize=W.size();
        vector<int> ans;
        if(kmp(S,W)) ans.push_back(0);  //0번 shift
        for(int j=1;j<Asize;j++) {    //shift 1번~ Asize-1번까지
            for(int k=0;k<Wsize;k++) {  // W의 모든 원소에 대해
                W[k] = A[(A.find(W[k])+1)%Asize];   //A에서 W의 다음위치를 찾아 W를 정해줌
            }
            if(kmp(S, W)) ans.push_back(j); //1개만 포함하는 경우의 shift를 저장
        }

        int ansSize = ans.size();
        if(ansSize == 0) cout << "no solution" << endl;
        else if(ansSize == 1) cout << "unique: " << ans[0] << endl;
        else {
            cout << "ambiguous: ";
            for(auto a:ans) cout << a << " ";
            cout << endl;
        }
    }

    return 0;
}
/*
문제 이해가 안가서 졸면서 한 40분 읽고서야 무슨 문제인지 이해를 했다..
알파벳 순서 A스트링을 기준으로 원문 W를 Shift해주고, Shift는 0 ~ A.size()-1만큼 가능하다.
그 Shift한 원문으로 암호문을 탐색하며 원문이 단 한 번만 나오는 Shift값을 구하는 것이다.
그냥 브루트포스로 탐색하면 shift*원문size*암호문size라는 긴 시간이 걸릴 것이기 때문에,
KMP를 활용하여 원문으로 암호문을 탐색하되, 원문이 하나만 나오는 경우를 찾는 것이 관건이다.
A는 최대 62, W는 50,000, S는 500,000이기 때문에 S를 여러번 탐색하거나 S*W로 탐색하면
무조건 시간초과가 났을 것이다. -> AC

*/