#include <iostream>
#include <algorithm>

using namespace std;

int map[1001][1001];

int main() {
    int n, m;
    cin >> n >> m;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++) 
            cin >> map[i][j];

    for(int i=1;i<=n;i++) {
        for(int j=1;j<=m;j++) {
            map[i][j] = max(max(map[i-1][j], map[i][j-1]), map[i-1][j-1]) + map[i][j];
        }
    }

    cout << map[n][m];

    return 0;
}

/*
dp문제이다. (1,1)부터 (n, m)까지 획득 가능한 최대 사탕의 개수를 저장해나가면 될 것 같다.
-> AC
*/