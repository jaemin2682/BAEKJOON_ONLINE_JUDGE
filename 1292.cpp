#include <iostream>

using namespace std;

int problem[1001];

int main() {
    int num=1, cnt=0;
    for(int i=1;i<=1000;i++) {
        if(num == cnt) {
            num++;
            cnt=0;
        }
        problem[i] = num;
        cnt++;
    }

    int a, b, sum=0;
    cin >> a >> b;
    for(int i=a;i<=b;i++) sum+=problem[i];
    cout << sum;

    return 0;
}
// 사전에 값을 다 넣어주어서 풀었다.