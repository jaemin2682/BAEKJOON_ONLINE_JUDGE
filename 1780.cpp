#include <iostream>
#include <math.h>
using namespace std;

int paper[2200][2200], Minus=0, Zero=0, Plus=0;

void devide(int sx, int ex, int sy, int ey) {
    bool check = true;
    int color = paper[sx][sy];
    for(int i=sx;i<=ex;i++) { //첫원소와 다른 원소가 있으면 탈출하고 check=false로
        for(int j=sy;j<=ey;j++) {
            if(paper[i][j] != color) {
                check = false;
                break;
            }
        }
        if(!check) break;
    }

    if(!check) {    //같지 않으면 9등분해서 함수 실행
        int factor = (ex-sx+1)/3;
        for(int i=0;i<3;i++) {
            for(int j=0;j<3;j++) {
                devide(sx+factor*i, sx+factor*(i+1)-1, sy+factor*j, sy+factor*(j+1)-1);
            }
        }
    }
    else {  //같으면 카운트 올리기
        if(paper[sx][sy] == -1) Minus++;
        else if(paper[sx][sy]==0) Zero++;
        else if(paper[sx][sy]==1) Plus++;
    }
}

int main() {
    int n;
    cin >> n;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            cin >> paper[i][j];
    devide(1, n, 1, n);
    cout << Minus << endl << Zero << endl << Plus ;

    return 0;
}
/*
분할정복 문제. 전체 원소가 같은지 확인하고, 같지 않으면 9등분해서 재실행,
같으면 숫자 판단해서 카운트 올리는 식으로 풀 것이다.

*/