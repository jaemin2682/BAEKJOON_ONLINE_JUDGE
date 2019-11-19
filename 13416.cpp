#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int t;
    cin >> t;
    for(int i=0;i<t;i++) {
        int n, sum=0;
        cin >> n;
        for(int j=0;j<n;j++) {
            int A, B, C;
            cin >> A >> B >> C;
            if(A > 0 || B > 0 || C > 0) {
                int MaxVal = max(A, B);
                MaxVal = max(MaxVal, C);
                sum += MaxVal;
            }
        }
        cout << sum << endl;
    }

    return 0;
}