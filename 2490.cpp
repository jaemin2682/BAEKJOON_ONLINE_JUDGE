#include <iostream>
using namespace std;

char arr[5] = {'E', 'A', 'B', 'C', 'D'};

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    for(int i=0;i<3;i++) {
        int cnt=0;
        bool num;
        for(int j=0;j<4;j++) {
            cin >> num;
            if(!num) cnt++;
        }
        cout << arr[cnt] << endl;
    }
    return 0;
}
//등과 배의 수를 세어, 문제의 조건에 맞는 출력을 출력한다.