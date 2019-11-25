#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    vector<pair<int, int>> arr(8);
    for(int i=0;i<8;i++) {
        cin >> arr[i].first;
        arr[i].second = i+1;
    }
    sort(arr.begin(), arr.end(), greater<pair<int, int>>());
    int sum = 0;
    for(int i=0;i<5;i++) sum += arr[i].first;
    cout << sum << endl;

    vector<int> order;
    for(int i=0;i<5;i++) order.push_back(arr[i].second);
    sort(order.begin(), order.end());
    for(int i=0;i<5;i++) cout << order[i] << " ";
    

    return 0;
}

/*
pair로 입력받을 때 각 점수와 문제 번호를 저장해놓고, 점수를 내림차순 정렬한다.
높은 5개의 점수의 합을 출력하고, 그들의 문제 번호를 출력한다.
*/