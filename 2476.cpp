#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, maxreward=0;
    cin >> n;
    for(int i=0;i<n;i++) {
        int one, two, three, reward=0;
        cin >> one >> two >> three;
        if(one==two && two==three) reward = 10000 + one*1000;
        else if(one==two || two==three) reward = 1000 + two*100;
        else if(one==three) reward = 1000 + one*100;
        else reward = max(max(one, two), three) * 100;
        maxreward = max(maxreward, reward);
    }
    cout << maxreward;
    
    return 0;
}

// 문제가 요구하는 대로만 그대로 풀면 된다.