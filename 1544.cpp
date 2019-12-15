#include <iostream>
#include <string>
#include <map>
using namespace std;

int n;
string str;
map<int, string> m;

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    int idx = 0;    //map의 인덱스 겸 cnt 역할으 할 변수
    for(int i=0;i<n;i++) {
        cin >> str;
        int msize = m.size();
        bool isfound = false;
        for(int j=0;j<msize;j++) {  //map을 찾아본다.
            if(m[j].find(str) != m[j].npos && m[j].size()/2 == str.size()) {//절반크기여야 함
                isfound = true;
                break;    
            }
        }
        if(!isfound) {  //새로운 단어이면 맵에 추가한다.
            str += str;
            m[idx] = str;
            idx++;
        }
    }
    cout << idx;

    return 0;
}
/*
사이클이 있는 단어와 같은지 여부를 찾는 문제인데,
나는 사이클이 있는 문자를 * 2 해서 포함하는지 찾는 방법을 자주 사용한다.
인덱스를 활용한 맵을 사용해서 풀었다. -> 틀렸습니다

2 a aa / 2 aa a  와 같은 입력이 들어왔을 때, 같은 단어로 세버려서
맵에 *2한 문자의 size의 절반이어야 같은 문자열로 체크하도록 했다.
사이클 단어는 같은 길이의 단어여야 하니까. -> AC
*/