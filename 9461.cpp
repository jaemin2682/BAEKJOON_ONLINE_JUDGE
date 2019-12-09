#include <iostream>
using namespace std;

long long dp[101];
int T, N;

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    
    for(int i=1;i<=3;i++) dp[i] = 1;
    for(int i=4;i<=5;i++) dp[i] = 2;
    for(int i=6;i<=100;i++) {
        dp[i] = dp[i-1] + dp[i-5];
    }
    cin >> T;
    for(int i=0;i<T;i++) {
        cin >> N;
        cout << dp[N] << endl;
    }

    return 0;
}
/*
1: 1
2: 1
3: 1
4: 2
5: 2
6: 3
7: 4
8: 5
9: 7
10: 9
11: 12
12: 16
규칙 : dp[x-4]만큼을 더한다.

*/