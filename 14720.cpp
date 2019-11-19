#include <iostream>

using namespace std;

int main () {
    int n, want=0, cnt=0;
    cin >> n;
    for(int i=0;i<n;i++) {
        int num;
        cin >> num;
        if(want == num) {
            cnt ++;
            want = (want+1)%3;
        }
    }

    cout << cnt;
    return 0;
}