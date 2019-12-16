#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <memory.h>
using namespace std;

int n, cnt;

bool isSame(string a, string b) {
    bool Aset[26], Bset[26];
    memset(Aset, false, sizeof(Aset));
    memset(Bset, false, sizeof(Bset));
    int size = a.size();
    for(int i=0;i<size;i++) Aset[a[i]-'a'] = true;
    for(int i=0;i<size;i++) Bset[b[i]-'a'] = true;
    int Acnt=0, Bcnt=0;
    for(int i=0;i<26;i++) if(Aset[i]) Acnt++;
    for(int i=0;i<26;i++) if(Bset[i]) Bcnt++;
    if(Acnt==Bcnt) return true;
    else return false;
}

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    vector<string> list(n);
    for(int i=0;i<n;i++) cin >> list[i];

    for(int i=0;i<n-1;i++) {
        for(int j=i+1;j<n;j++) {
            if(list[i].size() == list[j].size()) {
                if(isSame(list[i], list[j])) {
//                    cout << list[i] << " " << list[j] << "||||";
                    map<char, int> m;
                    string tem = list[i];
                    int liSize = list[i].size();
                    for(int k=0;k<liSize;k++) {
                        if(m.find(tem[k]) == m.end()) { //처음 검색되는 알파벳이면
                            m[tem[k]] = k;  //해당 알파벳과 인덱스를 저장
                            tem[k] = list[j][k]; //그리고 b의 알파벳 넣음
                        }
                        else {  //검색된 적이 있으면
                            tem[k] = list[j][m[tem[k]]];    //해당 b의 알파벳 넣음
                        }
                    }
//                    cout << tem << "  " << list[j] << endl;
                    if(tem == list[j]) {
                        cnt++;
                    }
                }
            }   
        }
    }
    cout << cnt;
    return 0;
}

/*
비슷하단 것을 정의해야 한다.
1. 글자 수가 같다.
2. 이루고 있는 글자의 종류 수가 같다.
3. a의 특정 알파벳을 바꾸어서, b를 만들 수 있다.
2중 for문으로 모든 조합을 확인해 보며, 글자 수가 같고 글자 종류 수가 같은 단어들에 대해
a를 돌며, 처음 보는 알파벳을 만났을 때 그 알파벳이 처음 나온 a의 인덱스에 해당하는
인덱스의 b의 알파벳으로 a에 나온 해당 알파벳들을 전부 바꿔주면서 간다.
-> AC
*/