#include <iostream>
#include <string>

using namespace std;

int main() {
    string year2018;
    cin >> year2018;
    int two=0, zero=0, one=0, eight=0;
    for(int i=0;i<year2018.size();i++) {
        if(year2018[i] == '0') zero++;
        else if(year2018[i] == '1') one++;
        else if(year2018[i] == '2') two++;
        else if(year2018[i] == '8') eight++;
        else {
            cout << 0;
            return 0;
        }
    }

    if(zero && one && two && eight) {
        if(zero==one && one==two && two==eight) cout << 8;
        else cout << 2;
    }
    else cout << 1;

    return 0;
}