#include <iostream>
#include <string>
using namespace std;

int n, cnt;

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i=0;i<n;i++) {
        string str;
        cin >> str;
        if(str.find("CD") != str.npos) cnt++;   //CD 포함 안되면 cnt++;
    }
    cout << n - cnt;
    return 0;
}
/*
영어 문제라 그런지 문제가 잘 와닿지 않는데...
Chains of Ice을 사용한 후 Death Grip를 사용하면 진다는거 같다 ㅋㅋ...
C-D가 이어진 전투를 카운트해서 전체에서 빼 주자. -> AC
*/