#include <iostream>

using namespace std;

int main() {
    int t;
    cin >> t;
    for(int i=0;i<t;i++) {
        int n, sum=0;
        cin >> n;
        for(int j=0;j<n;j++) {
            int num;
            cin >> num;
            sum += num;
        }
        cout << sum << endl;
    }
    return 0;
}
/*
합을 구하는 간단한 문제이다.
*/