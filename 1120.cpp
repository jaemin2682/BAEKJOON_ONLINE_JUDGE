#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string a, b;
int MinNotEqual = 50+1;

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin >> a >> b;
    for(int i=0;i<=b.size() - a.size();i++) { // 0 ~ A와 B의 size 차이
        int NotEqual = 0;
        for(int j=0;j<a.size();j++) {   //A에 대해
            if(a[j] != b[j+i]) NotEqual++;
        }
        MinNotEqual = min(MinNotEqual, NotEqual);
    }
    
    cout << MinNotEqual;

    return 0;
}
/*
우선, 앞에서 추가하면 문자열들이 밀리기 때문에 0~(Bsize-Asize)만큼 문자열을 밀었을 때
어느 경우가 가장 많은 문자열이 겹치나 체크한다.
-> 가장 많은 문자열이 겹치는 만큼 A를 shift하고, 앞에서 추가하는 문자열은 어차피
B와 겹치게 추가할 수 있기 때문에 B와 겹친다고 쳐도 무방하다.
-> 그리고 남은 Size만큼 A의 뒤에 추가하는데, 이 또한 겹친다고 봐도 무방하다.
-> 따라서, A를 오른쪽으로 최대한 겹치게 Shift했을 때 B와 겹치지 않는 문자의 최소 수가 답이다.
-> AC
*/