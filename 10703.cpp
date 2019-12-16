#include <iostream>
#include <string>
#include <vector>
#include <math.h>
#include <algorithm>
#include <memory.h>
using namespace std;

int r, s;
char star[3001][3001];
char star2[3001][3001];
vector<pair<int, int>> spot;  //유성의 거리 집합

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    memset(star2, '.', sizeof(star2));
    cin >> r >> s;
    for(int i=1;i<=r;i++)
        for(int j=1;j<=s;j++) {
            cin >> star[i][j];
            if(star[i][j] == '#') star2[i][j] = '#';    //#은 복사
            else if(star[i][j] == 'X') spot.push_back({i, j});  //X좌표 저장
        }

    vector<int> dis;    //땅과 유성의 거리 배열
    for(int i=1;i<=s;i++) {
        int distance = -1, check=-1;
        for(int j=1;j<=r;j++) {
            if(star[j][i] == 'X') {
                distance = j;
                check = 1;
            }
            else if(star[j][i] == '#' && check==1) {
                distance = abs(distance - j) - 1;
                check = 0;
            }
        }
        if(distance != -1) dis.push_back(distance);
    }

    int minDis = 3001;
    for(int a : dis) minDis = min(minDis, a);   //거리의 최소값 구함

    for(pair<int, int> a: spot) star2[a.first+minDis][a.second] = 'X';  //X 덧씌워준다.
    
    for(int i=1;i<=r;i++) {
        for(int j=1;j<=s;j++) cout << star2[i][j];
        cout << '\n';
    }

    return 0;
}
/*
첫 배열을 받고, X가 있는 열에 대해서만 가장 밑의 X와 가장 위의 #의 거리-1을 구한다.
그 거리 중 최소값을 구한다.(실제로 내릴 거리)
다른 배열을 만들어 .를 채워넣고, #은 그대로 복사한다.
X의 좌표를 저장해 놓고, 만든 배열에 X좌표에서 최소거리만큼 행을 더한 자리에 X를 넣어준다.
-> AC
*/