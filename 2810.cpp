#include <iostream>
#include <string>
using namespace std;

int n, Lcnt;
string seat;

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> seat;
    int size = seat.size();

    for(int i=0;i<size;i++) {
        if(seat[i] == 'L') {
            Lcnt++;
            i++;
        }
    }
    if(Lcnt==0) cout << n;
    else cout << n+1-Lcnt;

    return 0;
}
/*
N명일 때, 원래는 총 10개의 컵홀더가 있다. 그리고 LL(커플) 한 쌍당 가용 컵홀더가 1씩 줄어든다.
*/