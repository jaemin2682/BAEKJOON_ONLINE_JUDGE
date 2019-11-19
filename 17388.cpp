#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int s, k, h;
    cin >> s >> k >> h;

    if(s + k + h >= 100) cout << "OK";
    else {
        int minVal = min(s, k);
        minVal = min(minVal, h);
        if(minVal == s) cout << "Soongsil";
        else if(minVal == k) cout << "Korea";
        else cout << "Hanyang";
    }

    return 0;
}