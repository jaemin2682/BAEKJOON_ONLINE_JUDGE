#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <set>
#include <map>
using namespace std;

int n;

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    vector<int> arr(n);
    vector<int> P(n, -1);
    for(int i=0;i<n;i++) cin >> arr[i];
    for(int i=0;i<n;i++) {
        P[i] = 0;
        for(int j=0;j<n;j++)    //arr[i]보다 작은 숫자 개수 세기
            if(arr[i] > arr[j]) P[i]++; //1 2 0

        while(1) {
            bool ok = false;
            for(int k=0;k<n;k++) {
                if(i!=k && P[i]==P[k]) {    //같은 수가 나오면 뒤의 수는 ++
                    P[i]++;
                    ok = true;
                }
            }
            if(!ok) break;
        }
    }
    for(int i=0;i<n;i++) cout << P[i] << ' ';
    cout << '\n';

    return 0;
}
/*
2 3 1
1 0 2
1 2 0
1 2 3
*/