#include <iostream>

using namespace std;

int main() {
    int n, sum=0;
    cin >> n;
    for(int i=0;i<n;i++) {
        int student, apple;
        cin >> student >> apple;
        sum += apple%student;
    }
    cout << sum;

    return 0;
}
/*
간단한 수학문제이다.
*/