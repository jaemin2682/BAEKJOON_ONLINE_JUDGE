#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    int t;
    cin >> t;
    for(int i=0;i<t;i++) {
        int n, sum=0, maxVal=0, idx;
        vector<int> v(n+1);
        cin >> n;
        for(int j=1;j<=n;j++) {
            cin >> v[j];
            sum += v[j];
            if(maxVal < v[j]) {
                maxVal = v[j];
                idx = j;
            }
        }
        int cnt=0;
        for(int j=1;j<=n;j++)
            if(v[j] == maxVal) cnt++;

        if(cnt >= 2) cout << "no winner" << endl;
        else if(maxVal > sum/2) cout << "majority winner " << idx << endl;
        else cout << "minority winner "  << idx << endl;
    }

    return 0;
}
/*
문제를 재해석 할 필요가 없는 하드코딩 문제
*/