#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <set>
#include <map>
using namespace std;

int n;
const int INF = 1001;

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    vector<int> box(n);
    for(int i=0;i<n;i++) cin >> box[i];

    vector<int> lis;    //lis 수열
    int cnt = 0;
    lis.push_back(-INF);
    for(int i=0;i<n;i++) {
        if(lis.back() < box[i]) {
            lis.push_back(box[i]);
            cnt++;
        }
        else {
            auto idx = lower_bound(lis.begin(), lis.end(), box[i]);
            *idx = box[i];
        }
    }
    cout << cnt;
    return 0;
}
/*
최장 증가 수열(LIS)를 찾으면 되는 문제였다. 최대 상자 개수만 구하면 되기 때문에
기본적인 LIS만 구현하면 된다.
*/