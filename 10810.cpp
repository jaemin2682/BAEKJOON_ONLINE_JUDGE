#include <iostream>
#include <string>
#include <vector>
using namespace std;

int n, m;

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    vector<int> bascket(n+1, 0);
    
    for(int a=0;a<m;a++) {
        int i, j, k;
        cin >> i >> j >> k;
        for(int b=i;b<=j;b++) bascket[b] = k;   //i~j까지 k로 바꿔준다.
    }

    for(int a=1;a<=n;a++) cout << bascket[a] << " ";
}
/*
문제 조건만 잘 이해하고 작성하면 되는 간단한 구현 문제였다.
*/