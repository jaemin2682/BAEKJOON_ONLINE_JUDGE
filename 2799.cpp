#include <iostream>
#include <string>

using namespace std;

char window[501][501];

int main() {
    int m, n;
    cin >> m >>n;
    int y=1, x=1, score0=0, score1=0, score2=0, score3=0, score4=0;
    for(int i=0;i<5*m+1;i++)
        for(int j=0;j<5*n+1;j++)
            cin >> window[i][j];
    
    for(int i=0;i<m;i++) {
        x=1;
        for(int j=0;j<n;j++) {
            if(window[y][x]=='.') score0++;
            else if(window[y+1][x]=='.') score1++;
            else if(window[y+2][x]=='.') score2++;
            else if(window[y+3][x]=='.') score3++;
            else score4++;
            x+=5;
        }
        y+=5;
    }

    cout << score0 << " " << score1 << " " <<score2 << " " <<score3 << " "<< score4;

    return 0;
}