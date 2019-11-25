#include <iostream>

using namespace std;

int main() {
    int t;
    cin >> t;
    for(int i=0;i<t;i++) {
        double cost;
        cin >> cost;
        int quarter=0, dime=0, nickel=0, penny=0;
        
        quarter = cost/25; cost -= quarter * 25;
        dime = cost/10; cost-= dime * 10;
        nickel = cost/5; cost-= nickel * 5;
        penny = cost/1;

        cout << quarter << " " << dime << " " << nickel << " " <<penny << endl;
    }

    return 0;
}

/*
간단한 계산문제이다.
*/