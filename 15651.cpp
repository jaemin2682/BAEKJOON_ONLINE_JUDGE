#include <iostream>
using namespace std;

int n, m;
int arr[8];

void back(int cnt) {
    if(cnt==m) {
        for(int i=0;i<m;i++) cout << arr[i] << " ";
        cout << "\n";
        return;
    }
    for(int i=1;i<=n;i++) {
        arr[cnt] = i;
        back(cnt+1);
    }
}

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    back(0);

    return 0;
}
//중복 허용이기 때문에, 재귀적으로 부분수열을 다 출력해준다.