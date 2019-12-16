#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

int n;
vector<string> list;
map<string, int> m;

bool cmp(string a, string b) {
    int asize=a.size(), bsize=b.size();
    for(int i=0, j=0;i<asize || j<bsize;i++, j++) { //i:a, j:b
        string tema, temb;
        if(i!=asize-1 && a[i]=='n' && a[i+1]=='g') tema = "ng";
        else tema += a[i];
        if(j!=bsize-1 && b[j]=='n' && b[j+1]=='g') temb = "ng";
        else temb += b[j];

        if(m[tema] < m[temb]) return true;
        else if(m[tema] > m[temb]) return false;
    }
    if(asize > bsize) return false;
    else return true;
}

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin >> n;

    m["a"]=0, m["b"]=1, m["k"]=2, m["d"]=3, m["e"]=4, m["g"]=5, m["h"]=6, //정렬기준
    m["i"]=7, m["l"]=8, m["m"]=9, m["n"]=10, m["ng"]=11, m["o"]=12, m["p"]=13,
    m["r"]=14, m["s"]=15, m["t"]=16, m["u"]=17, m["w"]=18, m["y"]=19;

    for(int i=0;i<n;i++) {
        string str;
        cin >> str;
        list.push_back(str);
    }
    sort(list.begin(), list.end(), cmp);
    for(string a : list) cout << a << '\n';

    return 0;
}
/*
새로운 알파벳에 맞는 새로운 정렬조건을 지정해주면 되는 문제였다.
나같은 경우는, 그냥 단순하게 map에 각 새 알파벳에 대한 번호를 매겨주었다.
그리고 비교함수를 짜 문자열들을 비교하였다. -> AC
*/