#include <iostream>

using namespace std;

int main() {
    int n, sum=0;
    cin >> n;
    cout.precision(10);
    for(int i=0;i<n;i++) {
        int num;
        cin >> num;
        int temp=1;
        for(int i=0;i<num%10;i++) temp *= num/10;
        sum += temp;
    }
    cout << sum;

    return 0;
}