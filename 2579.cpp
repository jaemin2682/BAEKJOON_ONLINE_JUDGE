#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
int dp[301];

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    vector<int> stair(N);
    for(int i=0;i<N;i++) cin >> stair[i];
    
    if(N==1) cout << stair[0];
    else if(N==2) cout << stair[0] + stair[1];
    else if(N==3) {
        if(stair[1] >= stair[0]) cout << stair[1] + stair[2];
        else cout << stair[0] + stair[2];
    }
    else {
        dp[0] = stair[0];
        dp[1] = stair[0] + stair[1];
        dp[2] = max(stair[0], stair[1]) + stair[2];
        
        for(int i=3;i<N;i++) {
            dp[i] = max(dp[i-3]+stair[i-1]+stair[i], dp[i-2]+stair[i]);
        }
        cout << dp[N-1];
    }
    return 0;
}
/*
계단은 한 계단 or 두 계단 올라가기 가능 / 연속 3계단 밟기 불가능(시작점은 계단 X)
마지막 계단은 무조건 밟아야 함. 점수의 최댓값 구하기
X O O(전 계단을 밟은 경우) or O X O (전 계단을 밟지 않은 경우)
dp[i] = dp[i-3] + stair[i-1] + stair[i];
dp[i] = dp[i-2] + stair[i];

*/