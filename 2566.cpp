#include <iostream>

using namespace std;

int main() {
    int indX, indY, maxNum=0;
    for(int i=1;i<=9;i++) {
        for(int j=1;j<=9;j++) {
            int num;
            cin >> num;
            if(maxNum < num) {
                indX = i;
                indY = j;
                maxNum = num;
            }
        }
    }
    cout << maxNum << endl << indX << " " <<indY;

    return 0;
}
/*
입력 받을 때마다 최대값을 계산해주자.
*/