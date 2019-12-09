#include <iostream>
#include <algorithm>
using namespace std;

int N;
int price[1000+1][3];
int cache[3], RGB[3];

int main() {
    cin.sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    for(int i=1;i<=N;i++)
        for(int j=0;j<3;j++)
            cin >> price[i][j];
    
    RGB[0] = price[1][0];
    RGB[1] = price[1][1];
    RGB[2] = price[1][2];

    for(int i=2;i<=N;i++) {
        for(int j=0;j<3;j++) cache[j] = RGB[j];

        RGB[0] = price[i][0] + min(cache[1], cache[2]);
        RGB[1] = price[i][1] + min(cache[0], cache[2]);
        RGB[2] = price[i][2] + min(cache[1], cache[0]);
    }
    
    cout << min(min(RGB[0], RGB[1]), RGB[2]);

    return 0;
}
/*
매 줄마다 각 집을 R / G / B로 칠할 떄의 비용이 주어진다.
첫 집부터, R G B를 골랐을 때의 세 경우로 시작한다.
한 집 씩 추가해가며 그 집의 R or G or B를 선택했을 때의 최솟값을 결정해준다.
최종 집까지 다 구한 후, 세 경우 중 가장 작은 값이 답이다.
*/