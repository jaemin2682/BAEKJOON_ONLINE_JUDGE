#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int r, c;
string road;
vector<pair<char, int>> score;  //팀, 거리

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin >> r >> c;
    for(int i=0;i<r;i++) {
        cin >> road;
        int size = road.size();
        for(int j=size-1;j>=0;j--) {
            if(road[j] >= '1' && road[j] <= '9') {
                score.push_back(make_pair(road[j], size-j)); //팀, 결승선과의 거리 저장
                break;
            }
        }
    }
    sort(score.begin(), score.end());
    int score_size = score.size();
    vector<int> ranking(score_size);

    int rank_idx = 1;
    for(int i=1;i<=50;i++) {
        bool check = false;
        for(int j=0;j<score_size;j++) {
            if(i == score[j].second) {
                check = true;
                ranking[j] = rank_idx;
            }
        }
        if(check) rank_idx++;
    }
    
    for(int i=0;i<score_size;i++) cout << ranking[i] << endl;
    
    return 0;
}

/*
각 행을 받을 때마다, 팀 명과 도착지와의 거리를 vector<pair> 자료구조에 넣어 주었다.
그 후, 팀 이름으로 오름차순 정렬하고 도착지와의 거리의 순위를 구해 새로운 vector에 넣어준다.
-> AC
*/