#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int minval=101, sum=0;
    for(int i=0;i<7;i++) {
        int num;
        cin >> num;
        if(num%2==1) {
            sum+=num;
            minval = min(minval, num);
        }
    }
    if(sum==0) cout << -1;
    else cout << sum << endl << minval;

    return 0;
}