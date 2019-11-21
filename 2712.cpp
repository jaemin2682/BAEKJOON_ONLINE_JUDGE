#include <iostream>
#include <string>

using namespace std;

int main() {
    int t;
    cin >> t;
    for(int i=0;i<t;i++) {
        double value;
        string str;
        cin >> value >> str;

        if(str=="kg") printf("%.4f lb\n", value * 2.2046);
        else if(str=="lb") printf("%.4f kg\n", value * 0.4536);
        else if(str=="l") printf("%.4f g\n", value * 0.2642);
        else if(str=="g") printf("%.4f l\n", value * 3.7854);
    }

    return 0;
}

/*
그냥 표를 적용시키면 되는 문제
*/