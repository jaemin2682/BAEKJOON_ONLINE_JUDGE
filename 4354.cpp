#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int n, k, num;
vector<int> arr;

vector<int> getpi(string p) {
    int psize = p.size(), j=0;
    vector<int> pi(psize, 0);
    for(int i=1;i<psize;i++) {
        while(j>0 && p[i]!=p[j]) j = pi[j-1];
        if(p[i] == p[j]) pi[i] = ++j; 
    }
    return pi;
}


int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    while(1) {
        string str;
        cin >> str;
        if(str==".") break; 
        auto defeat = getpi(str);

        if(str.size()%(str.size()-defeat.back()) == 0)
            cout << str.size()/(str.size()-defeat.back()) << '\n';
        else cout << 1 << '\n';
    }
    return 0;
}
/*
abcd 은 실패함수 마지막이 0이다 -> a^n으로 나타낼 수 없으므로, 전체문자열이 a 그 자체다. -> 1
aaaa 은 실패함수 마지막이 3이다 -> 값이 size-1이므로 모든 글자가 같으므로 답이 size이다.
ababab 은 실패함수 마지막이 4이다 -> size가 6인데 4이므로 6-4=2짜리 문자열이 반복된다.
따라서 size/2 = 3이다.

따라서 a^n으로 나타내어지는 n은 size / (size-back())으로 나타낼 수 있다.
하지만 ababa 같은 경우는 a^n으로 나타내면 n이 1이지만, 5/(5-3) = 2갸 된다.
즉 저 공식을 만족하려면 size-back이 size에 딱 나눠져야 한다.
그렇지 않으면 답은 항상 1이다.

*/
