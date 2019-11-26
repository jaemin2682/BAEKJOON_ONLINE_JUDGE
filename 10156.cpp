#include <iostream>

using namespace std;

int k, n, m;

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin >> k >> n >> m;
    int Need = k*n-m;

    if(Need >= 0) cout << Need;
    else cout << 0;
    
    return 0;
}
// 간단한 계산문제이다.