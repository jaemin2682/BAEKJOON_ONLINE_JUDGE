#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

int N, M, cnt;
string str;
priority_queue<string> NoEar, NoSee;
vector<string> NoEarSee;

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M;
    
    for(int i=0;i<N;i++) {
        cin >> str;
        NoEar.push(str);
    }
    for(int i=0;i<M;i++) {
        cin >> str;
        NoSee.push(str);
    }
    while(!NoEar.empty() && !NoSee.empty()) {
        if(NoEar.top() > NoSee.top()) NoEar.pop();
        else if(NoEar.top() < NoSee.top()) NoSee.pop();
        else {
            cnt++;
            NoEarSee.push_back(NoEar.top());
            NoEar.pop();
            NoSee.pop();
        }
    }
    cout << cnt << endl;
    for(int i=NoEarSee.size()-1;i>=0;i--) cout << NoEarSee[i] << endl;
    
    return 0;
}
/*
N, M은 50만까지 가능하다. 일일히 비교하면 시간초과가 날 것 같지만 해보자.
듣도 못한 이름들을 vector에 저장하고, 보도 못한 애들이 입력받을 때마다 같은 것이 있으면
듣보잡이다. => 역시 시간초과이다.

priority queue를 두 개 사용해서, 두 큐의 top을 계속 비교하면서 뽑는건 어떨까? => AC
*/