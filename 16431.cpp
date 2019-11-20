#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int br, bc, dr, dc, jr, jc;
    cin >> br >> bc >> dr >> dc >> jr >> jc;
    int DisD = abs(jr-dr) + abs(jc-dc);
    int DisB = max(abs(jr-br), abs(jc-bc));

    if(DisB > DisD) cout << "daisy";
    else if(DisB < DisD) cout << "bessie";
    else cout << "tie";

    return 0;
}