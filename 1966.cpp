#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int t;
    cin >> t;
    for(int i=0;i<t;i++) {
        int n, m;
        cin >> n >> m;
        vector<pair<int ,int>> print(n);
        for(int j=0;j<n;j++) cin >> print[j].first;
        print[m].second = 1;

        int cnt = 1, idx = 0, Maxval = 0;
        for(int j=0;j<n;j++) Maxval = max(Maxval, print[j].first);

        while(1) {   //출력 부분    
            if(print[idx].second == -1) {
                idx = (idx+1)%n;
                continue;
            }
            else if(print[idx].first == Maxval) {
                if(print[idx].second == 1) {
                    cout << cnt << endl;
                    break;
                }
                print[idx].second = -1;
                cnt++;
                Maxval = 0;
                for(int j=0;j<n;j++) {
                    if(print[j].second != -1) Maxval = max(Maxval, print[j].first);
                }
            }
            idx = (idx+1)%n;
        }
    }

    return 0;
}

/*
중요도를 체크해서 인쇄하는 프린터 큐를 만들어야 한다. 편의상 vector로 간단하게 구현한다.
문제 요구사항만 정확히 맞추면 어렵지 않을 것 같다.
pair의 vector를 선언해서 우리가 궁금한 문서를 체크해준다. -> 시간초과
최대값을 매번 구해 주는 것이 아닌 출력할 때만 구해주고, 벡터의 처음을 빼서 뒤로 다시 붙이는
방식이 아닌 index만 계속 이동해서 가리킬 수 있도록 해보자.
bool : 1은 알고자 하는 값, -1은 이미 출력한 값, 나머지는 0 -> AC
*/