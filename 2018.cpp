#include <iostream>

using namespace std;

int main() {
    int n, ans=0, num=1;
    cin >> n;
    while(num <= n) {
        int index = num;
        int sum=0;
        while(1) {
            sum += index;
            if(sum == n) {
                ans++;
                break;
            }
            else if(sum > n) break;
            index++;
        }
        num++;
    }
    cout << ans;

    return 0;
}