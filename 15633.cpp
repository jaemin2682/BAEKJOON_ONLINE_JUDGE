#include <iostream>

using namespace std;

int main() {
    int n, sum=0;
    cin >> n;
    for(int i=1;i<=n/2;i++) {   //약수를 모두 더함
        if(n%i == 0) {
            sum+=i;
        }
    }
    sum += n;   //n 더해줌

    cout << sum*5-24;

    return 0;
}
/*
자연이 n이 주어졌을 때, 1과 n을 포함한 n의 모든 약수의 합을 구한다.

이 문단은 광고 차단 기능을 쓰지 않는 유저에게만 보인다. 
BOJ에게 광고비를 제공할 의향이 있는 당신은 충분한 팬심을 가지고 있다. 
이제 구한 값에 5를 곱하고 24를 빼서 출력하면 된다.
???ㅋㅋㅋ
*/