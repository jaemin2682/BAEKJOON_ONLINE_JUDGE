#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;

    cout << n * (n-1);
    return 0;
}
/* 
N개의 옷과 바지를 가지고 있으며, 1~N번째의 옷이나 바지는 각각 다른 색깔이다.
얘는 같은 색깔의 옷, 바지 조합을 입고 싶지 않아한다. 몇가지 조합이 있겠는가?

중복이 가능하니 각 N개의 옷 * 겹치지 않는 N-1개의 바지가 답이다. -> AC

*/