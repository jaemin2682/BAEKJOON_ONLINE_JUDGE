#include<iostream>
#include<string>
#include <map>
#include <vector>
using namespace std;

int r, c;
char table[1000][1000];
vector<string> v;
int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin >> r >> c;
    for(int i=0;i<r;i++)
        for(int j=0;j<c;j++)
            cin >> table[i][j];

    map<string, int> init;
    bool isEnd = true;
    for(int i=0;i<c;i++) {  //v에 초기값(마지막 줄 값들) 넣어줌.  
        string word;
        word += table[r-1][i];
        v.push_back(word);
        if(init.find(word) == init.end()) init[word] = i; //없던 값이라면 넣어줌
        else isEnd = false; //있는 값이라면 중복이 있는 것임.
    }
    if(isEnd) { //첫값에 중복이 없었다면 바로 프로그램을 끝냄
        cout << r-1;
        return 0;
    }

    int cnt = r-2;
    for(int i=r-2;i>=1;i--) {  //첫째줄은 확인했고 마지막줄은 확인할 필요 없으므로
        for(int j=0;j<c;j++) v[j] += table[i][j]; //한 줄 추가
        map<string, int> m;
        bool ok = true;
        for(int j=0;j<c;j++) {  //중복체크
            if(m.find(v[j]) == m.end()) m[v[j]] = j;
            else {
                ok = false;
                break;
            }
        }
        if(ok) break;   //중복없으면 빠져나감
        else cnt--; //중복이라면 cnt 감소
    }
    cout << cnt;

    return 0;
}
/*
문자열을 입력받아 넣어주고, 행의 크기-1만큼 반복해서 중복이 있나 확인하고, 없으면 맨윗열 빼고
하는 식으로 반복하면 될 것 같다.
실제로 지울 필요 없이 시작 열 인덱스를 이용하고, map을 이용해 중복체크를 한다.
-> 시간초과

r, c는 최대 1000이다. O(1000*1000*1000) = O(1,000,000,000)이기에 너무 느렸나보다.
처음 단어를 빠르게 빼야하기 때문에, deque를 사용해보자.
단어 덱 만드는 데 c*r, cnt 세는 데 r*(c+c)이므로 총 O(rc)이다. O(1000*1000) -> 시간초과(?)
덱의 pop이 O(1)이 아닌가?...

고민좀 하고 왔다. 접근을 다르게 해보자.
마지막 한 줄만 남았다고 생각했을 때 단어들이 중복되지 않으면, 위에 몇줄을 추가하든
모든 단어들은 중복이 될 수 없다.
따라서, 맨 밑의 한 단어들에 중복이 없다면 cnt는 최대치인 r-1이다.
위로 한 줄을 추가하고, 두글자 단어들의 중복을 확인한다. 중복이 없다면 cnt는 r-2이다.
....
r-1줄일 때 단어들의 중복을 확인한다. 이 때 중복이 없다면 cnt는 1, 있다면 0이다.
-> AC

*/