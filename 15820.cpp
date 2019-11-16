#include <iostream>
#include <math.h>
using namespace std;

int main() {
    int S1, S2;
    cin >> S1 >> S2;
    bool Check1 = true, Check2 = true;
    for(int i=0;i<S1;i++) {
        long long RealAns, ManAns;
        cin >> RealAns >> ManAns;
        if(RealAns != ManAns) Check1 = false;

    }
    for(int i=0;i<S2;i++) {
        long long RealAns1, ManAns1;
        cin >> RealAns1 >> ManAns1;
        if(RealAns1 != ManAns1) Check2 = false;
    }

    if(Check1 && Check2) cout << "Accepted";
    else if(!Check1) cout << "Wrong Answer";
    else if(Check1 && !Check2) cout << "Why Wrong!!!";

    return 0;
}