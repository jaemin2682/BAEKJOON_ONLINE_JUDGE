#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <stack>
#include <algorithm>

using namespace std;

int n, cnt;

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    map<string, int> pre;
    vector<int> post(n);

    for(int i=0;i<n;i++) {
        string a;
        cin >> a;
        pre[a] = i;
    }
    for(int i=0;i<n;i++) {
        string b;
        cin >> b;
        post[pre[b]] = i;
    }

    for(int i=1;i<n;i++) {
        for(int j=i-1;j>=0;j--) {
            if(post[j] > post[i]) {
                cnt++;
                break;
            }
        }
    }

    cout << cnt;
    return 0;
}
/*
추월한 차량을 찾는 문제이다.
추월한 차량 외에 나머지 모든 차는 모두 순서가 그대로이거나 뒤로 밀린다.
배열의 인덱스를 이용해 인덱스가 작아진 차의 수를 찾는다.
처음 들어온 차들의 인덱스를 빠르게 찾을 수 있도록 map 자료구조를 활용하였다.

ZG431SN
ZG5080K
ST123D
ZG206A

ZG206A
ZG431SN
ZG5080K
ST123D

1 2 3 0
*/