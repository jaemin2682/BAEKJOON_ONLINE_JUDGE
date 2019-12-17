#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <set>
#include <map>
#include <queue>
using namespace std;

int n, m;
int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    vector<int> arr(n+1, 0);
    for(int i=1;i<=n;i++) {
        if(i==1) cin >> arr[i]; //첫번째 항은 그냥 저장
        else {
            cin >> arr[i];
            arr[i] += arr[i-1]; //누적합 만들어주기
        }
    }

    for(int i=0;i<m;i++) {
        int start, end, sum=0;
        cin >> start >> end;
        cout << arr[end] - arr[start-1] << '\n';    //누적합 이용해서 구간합을 구한다.
    }
       
    return 0;
}
/*
최대 100,000 크기의 배열에 대해 100,000번을 탐색하면 10,000,000,000번 돌아야 하기 때문에 time out이다.
따라서, n 크기의 배열을 만들어 누적합을 쌓아준다.
그리고 i~j의 구간합을 구할 때는 dp[j]에서 dp[i-1]을 빼주면 된다.
*/