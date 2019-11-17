#include <iostream>

using namespace std;

int main() {
    int cnt = 1;
    while(1) {
        int num;
        cin >> num;
        if(num==0) break;
        
        cout << cnt << ". ";
        if(num%2==0) cout << "even ";
        else cout << "odd ";
        num*=3;
        if(num%2 ==0) num/=2;
        else num = (num+1)/2;
        num*=3;
        cout << num/9 << endl;
        
        cnt++;
    }

    return 0;
}