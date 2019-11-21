#include <iostream>
#include <algorithm>

using namespace std;

int area[301][301];

int main() {
    int n, m;
    cin >> n >> m;
    for(int i=1;i<=n;i++)   //입력 받는다
        for(int j=1;j<=m;j++) 
            cin >> area[i][j];

    for(int i=1;i<=m;i++) area[1][i] += area[1][i-1];
    for(int i=1;i<=n;i++) area[i][1] += area[i-1][1];
   
    for(int i=2;i<=n;i++) {
        for(int j=2;j<=m;j++) {
            area[i][j] += max(area[i-1][j], area[i][j-1]);
        }
    }
    
    cout << area[n][m];

    return 0;
}

/*
dp문제.

1행은 오른쪽으로 가면서 값을 누적해나가고, 1열도 마찬가지로 처리한다.
2,2부터 n, m까지 자신의 왼, 위 값중 더 높은값 + 자신을 저장해나간다. -> AC
*/