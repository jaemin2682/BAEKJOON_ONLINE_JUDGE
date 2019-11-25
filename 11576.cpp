#include <iostream>
#include <vector>

using namespace std;

int main() {
    int a, b, m;
    cin >> a >> b >> m;
    vector<int> arr(m);
    for(int i=0;i<m;i++) cin >> arr[i];

    int dec = 0, factor = 1;
    for(int i=m-1;i>=0;i--) {   //10진법으로 만들기
        dec += factor*arr[i];
        factor*=a;
    }
    vector<int> hey;
    while(dec > 0) {    //B진법으로 만들기
        hey.push_back(dec%b);
        dec/=b;
    }

    for(int i=hey.size()-1;i>=0;i--) cout << hey[i] << " ";
    return 0;
}
/*
진법 변환 문제이다. A진법 수를 10진법으로 만들고 다시 나누어서 B진법으로 변환한다. -> AC
*/