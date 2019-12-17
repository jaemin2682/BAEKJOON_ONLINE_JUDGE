#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <set>
#include <map>
#include <queue>
using namespace std;

int n;
priority_queue<int, vector<int>, greater<int>> pq;

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i=0;i<n;i++) {
        int num;
        cin >> num;
        if(num==0) {
            if(pq.empty()) cout << "0\n";
            else {
                int res = pq.top();
                pq.pop();
                cout << res << '\n';
            }
        }
        else pq.push(num);
    }
       
    return 0;
}
/*
최소 힙을 priority queue를 내림차순으로 정렬하여 풀었다.
*/