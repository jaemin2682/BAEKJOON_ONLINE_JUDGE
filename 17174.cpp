#include <iostream>

using namespace std;

int main() {
    int n, m, cnt, rem;
    cin >> n >> m;
    cnt = n, rem=m;
    while(1) {
        if(m > n) break;
        cnt += n/m;
        m *= rem;
    }
    cout << cnt;
    return 0;
}