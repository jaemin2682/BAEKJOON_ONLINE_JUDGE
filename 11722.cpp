#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int n;

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    vector<int> lis;    //lis 벡터
    vector<int> arr(n);
    lis.push_back(-1);    //가장 큰 값 넣기
    for(int i=0;i<n;i++) cin >> arr[i];

    reverse(arr.begin(), arr.end());    //lis를 lds처럼 수행하기 위해 뒤집는다.
    for(int i=0;i<n;i++) {
        if(lis.back() < arr[i]) lis.push_back(arr[i]);
        else {
            auto idx = lower_bound(lis.begin(), lis.end(), arr[i]);
            *idx = arr[i];
        }
    }
    cout << lis.size()-1;
    
    return 0;
}
/*
lds 문제다. 배열을 받아 뒤집어서 lis를 실행하자.

*/
