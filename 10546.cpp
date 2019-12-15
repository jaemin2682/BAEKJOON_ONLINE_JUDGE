#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int n, idx=-1;
string name;
vector<string> partitions;
vector<string> completion;

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i=0;i<n;i++) {
        cin >> name;
        partitions.push_back(name);
    }
    for(int i=0;i<n-1;i++) {
        cin >> name;
        completion.push_back(name);
    }
    sort(partitions.begin(), partitions.end());
    sort(completion.begin(), completion.end());

    for(int i=0;i<n-1;i++) {
        if(partitions[i] != completion[i]) {
            idx = i;
            break;
        }
    }
    if(idx==-1) idx = n-1;  //참가자가 완주자보다 1명 많으므로, 따로 처리해준다.
    cout << partitions[idx];

    return 0;
}
/*
동명이인이 존재할 수 있기 때문에, 이름마다 카운트를 따로 세어도 되지만,
참가자 이름들과 완주자 이름들을 정렬하고, 처음으로 다른 이름이 나오는 인덱스를 찾으면 된다.
*/