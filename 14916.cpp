#include <iostream>

using namespace std;

int main() {
    int remain;
    cin >> remain;

    if((remain%5)%2 == 0) cout << remain/5 + (remain%5)/2;
    else {
        int five=remain/5, two=0;
        while(1) {
            if(five < 0) {
                cout << -1;
                return 0;
            }

            if((remain-five*5)%2==0) {
                two = (remain-five*5)/2;
                cout << five + two;
                break;
            }
            else {
                five--;
            }
        }
    }
    
    return 0;
}