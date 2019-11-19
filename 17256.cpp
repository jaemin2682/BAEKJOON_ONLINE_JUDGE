#include <iostream>

using namespace std;

int main() {
    int ax, ay, az, cx, cy, cz;
    cin >> ax >> ay >> az >> cx >> cy >> cz;
    // (ax ay az) I (bx by bz) = (az+bx, ay*by, ax+bz) = (cx cy cz)
    // bx = cx - az,  by = cy / ay, bz = cz - ax
    cout << cx-az << " " << cy/ay << " " << cz-ax;

    return 0;
}