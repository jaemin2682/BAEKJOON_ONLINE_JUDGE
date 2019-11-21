#include <iostream>

using namespace std;

char area[50][50];

int main() {
    int r, c, zero=0, one=0, two=0, three=0, four=0;
    cin >> r >> c;
    for(int i=0;i<r;i++)
        for(int j=0;j<c;j++)
            cin >> area[i][j];

    for(int i=0;i<r-1;i++) {
        for(int j=0;j<c-1;j++) {
            int Xcnt=0;
            bool sharpcnt = false;
            for(int a=i;a<=i+1;a++) {
                for(int b=j;b<=j+1;b++) {
                    if(area[a][b]=='X') Xcnt++;
                    else if(area[a][b]=='#') sharpcnt = true;
                }
            }
            if(sharpcnt) continue;
            else {
                if(Xcnt==0) zero++;
                else if(Xcnt==1) one++;
                else if(Xcnt==2) two++;
                else if(Xcnt==3) three++;
                else if(Xcnt==4) four++;
            }
        }
    }
    cout << zero << endl << one << endl << two << endl << three << endl << four;

    return 0;
}

/*
#:빌딩, X:주차된 차, .:빈 주차 공간
해빈이의 차는 2*2의 칸을 차지함
빌딩은 부수지 못하고, 주차된 차만 부술 수 있음

차 안부수고 주차가능한 공간의 개수, 차 한대를 부수고 주차가능한 공간의 개수, 두대, 세대, 네대 출력

*/