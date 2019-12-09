#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int N;
int dp[1000000+1];

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin >> N;

    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 3;

    int idx=4;
    while(idx <= N) {
        dp[idx] = (dp[idx-1] + dp[idx-2])%15746;
        idx++;
    }

    cout << dp[N] << "\n";

    return 0;
}

/*
0은 무조건 2개를 묶어서 써야하고, 1은 제약이 없다.
N이 주어지면, 2*a + b = N이 되어야 한다. a는 0의 개수, b는 1의 개수이다.
N=4라고 하면 a는 0, 1, 2가 가능하다.
a=0일 때, b=4 => 1111
a=1일 때, b=2 => 0011, 1001, 1100   //이 경우, 수열로 개수를 세자.
a=2일 때, b=0 => 0000
이렇게 총 5개이다. => 시간초과. 수열이 들어가면 안된다.

DP로 풀어야 하겠다. 
N=1일 때, 답은 1.(1)
N=2일 때, 답은 2. (11, 00)
N=3일 때, 답은 3. (111, 001, 100)
N=4일 때, 답은 5. (1111, 0011, 1001, 1100, 0000)
N=5일 때, 답은 8. (11111, 00111, 10011, 11001, 11100, 10000, 00001, 00100)
N=6일 때, 답은 13
N=7일 때, 답은 21
N=8일 때, 답은 34
-> 피보나치 수열이다.
1  2  3  5  8  13  21  34
*/