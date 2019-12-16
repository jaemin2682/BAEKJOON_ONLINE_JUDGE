#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

int n;

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i=0;i<n;i++) {
        string str;
        cin >> str;
        int strSize = str.size();
        str += str; //문자열을 두배로 더해준다.
        vector<pair<string, int>> arr;  //각 인덱스의 서브스트링과 인덱스를 저장한다.
        for(int j=0;j<strSize;j++) {
            string tem = str.substr(j, strSize);
            arr.push_back({tem, j});
        }
        sort(arr.begin(), arr.end());  //string 사전순, 인덱스 오름차순으로 정렬해준다.
        cout << arr[0].second + 1 << '\n';
    }


    return 0;
}
/*
목걸이는 circular하고, 각 인덱스에서 목걸이를 읽을 때 사전순으로 가장 작은 위치를
찾으면 된다. 여러개가 있을 경우, 가장 작은 인덱스를 출력한다.
문자열을 *2 해주고, 0번 인덱스에서 size-1번 인덱스까지 size만한 substr을 모으고,
그들을 정렬해주면 될 것 같다. -> AC
*/