#include <iostream>
#include <string>
using namespace std;

int n, m;
int arr[9];
bool visit[9];

void back(int cnt) {
    if(cnt==m) {    //원하는 수의 값을 얻었을 때
        for(int i=0;i<m;i++)
            cout << arr[i] << " ";
        cout << "\n";
        return;
    }
    for(int i=1;i<=n;i++) {
        if(!visit[i]) {
            visit[i] = true;    //방문체크
            arr[cnt] = i;       
            back(cnt+1);
            visit[i] = false;   //출력 후 방문체크 풀어줌(어차피 for문에서 더 큰 수로 감)
        }
    }
}

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;

    back(0);

    return 0;
}
/*
backtracking 기초문제이다. 처음으로 풀어보기 때문에 여러번의 시도를 하였다.
아직 직관적이지 않아 어렵다.
*/