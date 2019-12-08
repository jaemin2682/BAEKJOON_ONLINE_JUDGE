#include <iostream>
using namespace std;

int n, m;
int arr[9];
bool visit[9];

void back(int cnt) {
    if(cnt==m) {
        for(int i=0;i<m;i++) cout << arr[i] << " ";
        cout << "\n";
        return;
    }
    for(int i=1;i<=n;i++) {
        if(!visit[i]) {
            visit[i] = true;
            if(cnt==0 || (cnt>0 && arr[cnt-1] < i)) {
                arr[cnt] = i;
                back(cnt+1);
            }
            visit[i] = false;
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
기존 N과 M(1) 문제에 오름차순 조건을 추가하였다.
*/