#include <iostream>
#include <string>
#include <math.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    for(int i=0;i<n;i++) {
        string str;
        cin >> str;
        int rem = pow(2, 23);
        int ans = 0;
        for(int i=0;i<24;i++) {
            if(str[i] == '1') ans += rem;
            rem/=2;
        }
        cout << ans << endl;
    }


    return 0;
}
