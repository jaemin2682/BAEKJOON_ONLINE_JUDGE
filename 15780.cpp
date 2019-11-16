#include <iostream>

using namespace std;

int main() {
    int n, k, sum=0;
    cin >> n >> k;
    for(int i=0;i<k;i++) {
        int num;
        cin >> num;
        if(num%2==1) sum += num/2 + 1;
        else sum += num/2;
    }
    if(sum >= n) cout << "YES";
    else cout << "NO";

    return 0;
}