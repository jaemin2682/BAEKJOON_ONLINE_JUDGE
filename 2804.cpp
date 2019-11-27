#include <iostream>
#include <string>
#include <map>
using namespace std;

string A, B;
char maps[30][30];

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin >> A >> B;
    map<char, int> m;
    int Asize = A.size(), Bsize = B.size(), idxA, idxB;

    for(int i=0;i<Bsize;i++) m.insert(make_pair(B[i], i));  //B를 하나씩 넣는다.
    for(int i=0;i<Asize;i++)    //A의 인덱스를 찾는다.
        if(m.find(A[i]) != m.end()) {
            idxA = i;
            break;
        }
    for(int i=0;i<Bsize;i++)    //B의 인덱스를 찾는다.
        if(B[i] == A[idxA]) {
            idxB = i;
            break;
        }
    
    for(int i=0;i<Asize;i++) maps[idxB][i] = A[i];  //A 그리기
    for(int i=0;i<Bsize;i++) maps[i][idxA] = B[i];  //B 그리기

    for(int i=0;i<Bsize;i++) {
        for(int j=0;j<Asize;j++) {
            if(!maps[i][j]) cout <<'.';
            else cout << maps[i][j];
        }
        cout << endl;
    }
    return 0;
}
/*
A와 B에서 겹치는 단어 중에서, A에서 제일 먼저 등장하는 단어로 결정.
그 단어가 B에도 여러개 있다면, 가장 먼저 나타나는 단어로 결정.

단어를 결정하면, 그 단어의 열이 B가 세로로 위치할 열이다.
그리고 B에서 처음 그 단어가 나오면 그 단어가 나온 행이 A가 위치할 행이다.

map을 만들어 B의 글자를 모두 다 따로 넣는다. 그리고 A의 첫번째 글자부터 map에 있는 단어가 있나
확인한다. 그러다 있는 값이 나오면, 인덱스를 저장하고 빠져나온다.
이제 B를 돌면서 A의 그 인덱스의 값과 같은 값이 있나 찾고 그것의 인덱스를 저장하고 빠져나온다.
이제 첫번째로 얻은 인덱스가 B가 위치할 열이고, 두번째로 얻은 인덱스가 A가 위치할 행이다.
Let's get it~ -> AC
*/