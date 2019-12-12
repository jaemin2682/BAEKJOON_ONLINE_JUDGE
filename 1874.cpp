#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int n;
vector<char> ans;

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    vector<int> v(n);
    vector<bool> b(n+1, false);
    for(int i=0;i<n;i++) cin >> v[i];
    
    int idx=1;
    for(int i=0;i<n;i++) {
        if(idx <= v[i]) {
            while(idx<=v[i]) {  //도달할 때까지 +
                ans.push_back('+');
                idx++;
            }
            b[v[i]] = true;
            ans.push_back('-');
        }
        else {
            int c;
            for(int j = idx-1;j>=0;j--) {   //+한 애들 중 -하지 않은 가장 큰 수 찾기
                if(!b[j]) {
                    c = j;
                    break;
                } 
            }
            if(v[i] == c) {     //그 수가 맞을 때만 -.
                ans.push_back('-');
                b[v[i]] = true;
            }
        }
    }

    bool isright = true;
    for(int i=1;i<=n;i++)   //Yes/No 판단
        if(!b[i]) isright = false;
    
    if(isright) //출력부
        for(char a:ans) cout << a << '\n';
    else cout << "NO";


    return 0;
}
/*
따로 idx 변수를 두어, 현재 어디까지 push했는지 기억한다.
값이 idx보다 크면 그만큼 +를 해주고, 자기자신을 -해준다.
이 때, 가능한지 아닌지 판단해주기 위해 -한 애들은 bool배열에 표시를 해준다.
값이 idx보다 작을 때는, -할 수 있는 수 = +한 애들 중 -하지 않은 가장 큰 수임을 이용하여
그 수가 맞을 때만 -해 주었다.
그렇게 함으로써 bool배열에 false가 있으면 완벽한 +, -연산이 불가능함을 보일 수 있게 했다.

*/