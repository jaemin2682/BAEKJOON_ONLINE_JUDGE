#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>
#include <map>
using namespace std;

int n, k;
vector<string> list; //각 단어의 필요한 알파벳 모음
set<char> alpha;  //필요한 알파벳들의 총 모음

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k;
    for(int i=0;i<n;i++) {
        set<char> s;
        string str, newstr;
        cin >> str;
        int strSize = str.size();
        for(int j=0;j<strSize;j++) {    //a, n, t, i, c가 아니면 set에 넣는다.
            if(str[j]!='a' && str[j]!='n' && str[j]!='t' && str[j]!='i' && str[j]!='c') {
                s.insert(str[j]);
                alpha.insert(str[j]);
            }
        }
        set<char>::iterator iter;
        for(iter=s.begin();iter!=s.end();iter++) newstr+=*iter;
        list.push_back(newstr); //각 단어의 단어모음을 저장.
    }
    vector<char> alphav, n;
    set<char>::iterator iter;   //총 알파벳 모음을 set에서 vector로 옮김
    for(iter=alpha.begin();iter!=alpha.end();iter++) alphav.push_back(*iter);

    int alphavSize = alphav.size(); //조합뽑기 사전작업
    for(int i=0;i<alphavSize-k+5;i++) n.push_back('0');
    for(int i=0;i<k-5;i++) n.push_back('1');

    int maxcnt = 0, cnt, listSize = list.size();
    do {    //모든 조합 뽑기
        cnt = 0;
        map<char, bool> check;  //배운 단어 목록
        for(int i=0;i<alphavSize;i++)
            if(n[i] == '1') check[alphav[i]] = true;    //배운단어는 전부 넣어줌
        for(int i=0;i<listSize;i++) {   //각 단어에 대해
            int j = list[i].size();
            bool isGood = true;
            for(int k=0;k<j;k++) {  //배운단어로 한 단어를 모두 배울 수 있는지
                if(check.find(list[i][k]) == check.end()) {
                    isGood = false;
                    break;
                }
            }
            if(isGood) cnt++;
        }
        maxcnt = max(maxcnt, cnt);
    }while(next_permutation(n.begin(), n.end()));

    if(k<5) cout << 0;  //k가 5개 미만이면 무조건 못배운다.
    else cout << maxcnt;

    return 0;
}
/*
모든 단어는 anta로 시작해 tica로 끝난다. 그러므로 기본적으로 a,n,t,i,c의 5개의 글자가 필요하다.
antarctica     -> rc     ->   r
antahellotica  -> hello  ->   h,e,l,o
antacartica    -> car    ->   r
set에 쓴 단어들을 모두 모은다. 그리고 k-5개의 단어들에 대해 조합을 뽑는다.
그 모든 조합에 대해 몇 글자를 읽을 수 있는지 찾고, 최대값을 구한다.
26에서 5개를 빼 최대 21개에서 11개를 뽑으면, 35만 경우 정도. 충분하다.

생각보다 푸는데 꽤 오래 걸린 문제다.
시간제한이 1초였기 때문에, 메모리를 최대한 사용하는 대신 시간을 많이 줄이려고 노력하였다
-> AC
*/