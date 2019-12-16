#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;



int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    vector<string> list(6);
    vector<string> oklist;
    for(int i=0;i<6;i++) cin >> list[i];
    do {    //모든 경우에 대한 순열
        char puzzle[3][3];
        bool ok = true;
        for(int i=0;i<3;i++)    //1,2,3번째 단어를 1,2,3행에 넣어준다.
            for(int j=0;j<3;j++)
                puzzle[i][j] = list[i][j];
        for(int i=0;i<3;i++) {   //4,5,6번째 단어를 1,2,3열과 맞는지 체크한다.
            for(int j=0;j<3;j++) {
                if(puzzle[j][i] != list[i+3][j]) {
                    ok = false;
                    break;
                }
            }
            if(!ok) break;
        }
        if(ok) {    //만들 수 있다면, 1자배열로 만들어 저장해준다.
            string line;
            for(int i=0;i<6;i++) line += list[i];
            oklist.push_back(line);
        }
    } while(next_permutation(list.begin(), list.end()));

    sort(oklist.begin(), oklist.end()); //사전순으로 정렬한다.

    if(oklist.empty()) cout << 0;
    else {  //puzzle모양에 맞게 출력한다.
        for(int i=0;i<3;i++) {
            for(int j=0;j<3;j++) cout << oklist[0][j+3*i];
            cout << '\n';
        }
    }
    return 0;
}
/*
가로 세로 퍼즐이다. 규칙을 찾는 것이 중요해 보인다.
사전순으로 앞서는 것을 출력하라 했으니, 사전순으로 우위를 정하기 편하게 1자배열로 만든다.
3글자짜리 단어가 6개밖에 들어오지 않기 때문에, 모든 경우의 수에 대한 배열을 구해서
가능한 것 중 가장 사전순으로 앞인 것을 출력하면 될 것처럼 보인다.
받은 6개의 단어를 순열로 모든 경우의 수에 대해 준비한다.
그 중 앞의 3단어를 가로로 1행, 2행, 3행으로 두고 뒤 3단어를 세로로 1열, 2열, 3열에 둔다.
그 중 만족하는 애들만 벡터에 추가해준다. -> AC
*/