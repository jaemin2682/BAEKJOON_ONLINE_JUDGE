#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <set>
#include <map>
#include <queue>
using namespace std;

int n, tem, sum;

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i=0;i<n;i++) {
        int num;
        cin >> num;
        if(i==0) tem = num; //첫 수는 그대로 저장
        else {
            sum += tem*num; //현재 수와 저장한 수의 곱을 더해준다.
            tem += num; //저장한 수에 현재 수를 더해준다.
        }
    }
    cout << sum;
    
    return 0;
}
/*
문제 조건에 맞게 그대로 구현해주면 된다.
*/