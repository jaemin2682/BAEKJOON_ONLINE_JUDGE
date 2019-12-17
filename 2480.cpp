#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <set>
#include <map>
#include <queue>
using namespace std;

int one, two, three;
int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin >> one >> two >> three;
    if(one==two && two==three) cout << 10000+one*1000;  //세 눈금이 같을 때
    else if(one==two || two==three || one==three) { //두 눈금이 같을 때
        if(two == three) cout << 1000+two*100;
        else cout << 1000+one*100;
    }
    else {  //눈금이 모두 다를 때
        int maxnum = max(one, max(two, three));
        cout << maxnum*100;
    }
    
    
    return 0;
}
/*
문제 조건에 맞게 그대로 구현해주면 된다.
*/