#include <iostream>
using namespace std;

int n, m;
int arr[9];

void back(int cnt) {
    if(cnt == m) {
        for(int i=0;i<m;i++) cout << arr[i] << " ";
        cout << '\n';
        return;
    }
    for(int i=1;i<=n;i++) {
        if(cnt==0 || (i >= arr[cnt-1])) {
            arr[cnt] = i;
            back(cnt+1);
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
//비내림차순이기 때문에, 수열의 첫 값일 째를 제외하고 다음값이 전값보다 크거나 같아야 한다.