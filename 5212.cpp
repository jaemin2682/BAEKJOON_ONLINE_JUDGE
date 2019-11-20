#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

char map[12][12];

int main() {
    int r, c;
    cin >> r >> c;
    vector<pair<int, int>> rem;

    for(int i=1;i<=r;i++)
        for(int j=1;j<=c;j++)
            cin >> map[i][j];

    for(int i=0;i<=r+1;i++) {   //바깥면 처리
        map[i][0] = '.';
        map[i][c+1] = '.';
    }
    for(int i=0;i<=c+1;i++) {
        map[0][i] = '.';
        map[r+1][i] = '.';
    }

    for(int i=1;i<=r;i++) { //바꿀 애들 좌표 저장
        for(int j=1;j<=c;j++) {
            if(map[i][j]=='X') {
                int cnt=0;
                if(map[i-1][j]=='.') cnt++;
                if(map[i+1][j]=='.') cnt++;
                if(map[i][j-1]=='.') cnt++;
                if(map[i][j+1]=='.') cnt++;
                if(cnt>=3) rem.push_back({i, j});
            }
        }
    }

    for(int i=0;i<rem.size();i++) { //저장한 좌표들을 바꿔줌
        map[rem[i].first][rem[i].second] = '.';
    }


    int minX=13, maxX=0, minY=13, maxY=0;   //엣지 인덱스 정하기
    for(int i=1;i<=r;i++) {
        for(int j=1;j<=c;j++) {
            if(map[i][j] == 'X') {
                minY = min(minY, i);
                maxY = max(maxY, i);
                minX = min(minX, j);
                maxX = max(maxX, j);
            }
        }
    }

    for(int i=minY;i<=maxY;i++) {   //출력
        for(int j=minX;j<=maxX;j++) {
            cout << map[i][j];
        }
        cout << endl;
    }

    return 0;
}
/*
지구온난화를 늦추려는 노력이 필요하다. 남해가 위헙해!
상하좌우에 3칸 이상이 바다인 경우 육지가 바다가 된다.
출력지도의 크기는 육지를 모두 포함하는 가장 작은 직사각형이다.

2중 for문으로 모든 맵을 돌면서 상하좌우를 확인해 '.'가 3개 이상이면 '.'로 바꾼다. -> X
위의 방법은 '.'로 바꾼 'X'가 인접한 'X'에 영향을 미치기 때문에, 따로 저장해서 처리하자.
하지만, 입력받은 문자 밖의 영역은 바다라는 점을 고려하지 않았다 ㅋㅋㅋ 사이드에 넣어주자.

X찾기 : Y와 X의 최소, 최대값의 인덱스를 딴다.

-> AC
*/