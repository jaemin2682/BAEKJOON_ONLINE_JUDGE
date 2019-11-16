#include <iostream>

using namespace std;

int main() {
    int n, cnt=1, val=1;
    bool mode = true;
    cin >> n;
    
    while(n != cnt) {
        if(cnt%8==5) mode = false;
        else if(cnt%8==1) mode = true;

        if(mode) val++;
        else val--;
        cnt++;
    }
    cout << val;

    return 0;
}