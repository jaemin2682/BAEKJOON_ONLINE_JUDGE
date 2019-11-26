#include <iostream>

using namespace std;

bool check[31];

int main() {
    for(int i=1;i<29;i++) {
        int num;
        cin >> num;
        check[num] = true;
    }

    for(int i=1;i<31;i++)
        if(!check[i]) cout << i << endl;

    return 0;
}
// 출석한 번호를 bool 배열에 체킹하고, 그렇지 않은 번호를 출력한다.