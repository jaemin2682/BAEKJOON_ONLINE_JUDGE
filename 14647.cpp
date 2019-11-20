#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int bingo[501][501];

int main() {
    int n, m, colMax=0, rowMax=0, cnt=0;
    cin >> n >> m;
    for(int i=1;i<=n;i++) { //9의 개수 세기 + row 최대값 찾기 + 총 9의 개수 세기
        int row = 0;
        for(int j=1;j<=m;j++) {
            int rcnt=0;
            string str;
            cin >> str;
            for(int k=0;k<str.size();k++){
                if(str[k] == '9') {
                    row++;
                    cnt++;
                    rcnt++;
                }
            }
            bingo[i][j] = rcnt;
        }
        rowMax = max(rowMax, row);
    }

    for(int i=1;i<=m;i++) { //col 최대값 찾기
        int col = 0;
        for(int j=1;j<=n;j++)
            col += bingo[j][i];
        colMax = max(colMax, col);
    }

    cout << cnt - max(colMax, rowMax);  //전체 개수 - 가장 큰 행 또는 열의 9의 개수

    return 0;
}
/*
각 원소를 string으로 입력받아 9의 개수를 원소로 하는 배열을 만든다.
전체 9의 개수를 세고, 가장 많은 9를 가진 행 또는 열의 값을 전체에서 뺀다.
*/