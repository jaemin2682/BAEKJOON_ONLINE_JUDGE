#include<iostream>
#include<vector>
using namespace std;

int n, m;

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    vector<int> deleteList(m), queueList(n);
    for(int i=0;i<m;i++) cin >> deleteList[i];  //뽑아야 하는 원소 list
    for(int i=0;i<n;i++) queueList[i] = i+1;    //1~N 넣음
    
    int idx = 0, cnt = 0;
    for(int i=0;i<m;i++) {  //deleteList의 각 수에 대해
        if(deleteList[i] == queueList[idx]) {   //이미 같으면
            bool isLast = false;    //idx가 마지막일 때 예외처리
            if(idx == queueList.size()-1) isLast = true;
            queueList.erase(queueList.begin() + idx);//지움. idx는 자연히 원래 원소의 오른쪽 가리킴
            if(isLast) idx = 0;
        }
        else {
            int qSize = queueList.size(), targetidx;
            for(int j=0;j<qSize;j++)    //뽑을 원소 찾음
                if(queueList[j] == deleteList[i]) {
                    targetidx = j;
                    break;
                }
            bool isright = false;
            if(idx > targetidx) {   //idx > targetIdx
                if(idx - targetidx > queueList.size() - idx + targetidx) isright = true;
            }   //left로 갔을 때의 거리가 더 크면 right로 간다.
            else {  //idx <= targetIdx
                if(idx + queueList.size() - targetidx > targetidx - idx) isright = true;
            }

            while(deleteList[i] != queueList[idx]) {
                if(isright) idx = (idx+1)%queueList.size();
                else {
                    idx-=1;
                    if(idx==-1) idx = queueList.size()-1;
                }
                cnt++;
            }
            bool isLast = false;    //idx가 마지막일 때 예외처리
            if(idx == queueList.size()-1) isLast = true;
            queueList.erase(queueList.begin() + idx);
            if(isLast) idx = 0;
        }

    }
    cout << cnt;
    return 0;
}
/*
직접 원소를 움직일 필요는 없어 보여, 인덱스를 활용해 첫째 원소를 가리키는것처럼 사용했다.
뽑아야 할 원소의 인덱스를 찾고, 그 인덱스에 접근하려면 왼쪽으로의 회전이 빠른지
오른쪽이 빠른지 판단한다. 그 후 인덱스를 정한 방향으로 움직이며 카운트를 늘려 나간다.
인덱스를 옮길 때 원형으로 돌 수 있도록 해 주었고,
마지막 원소를 지울 때 인덱스가 처음으로 돌아가게 해주는 예외처리가 중요했다. -> AC
*/