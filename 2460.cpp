#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int number=0, maxnum=0;
    for(int i=0;i<10;i++) {
        int out, in;
        cin >> out >> in;
        number += in - out;
        maxnum = max(number, maxnum);
    }
    cout << maxnum;
    return 0;
}