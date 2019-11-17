#include <iostream>
#include <string>

using namespace std;

int main() {
    while(1) {
        int n;
        cin >> n;
        if(n==0) break;
        cout << n << " ";
        while(n > 9) {
            string tem = to_string(n);
            int sum = 1;
            for(int i=0;i<tem.size();i++) sum *= tem[i] - 48;
            n = sum;
            cout << n << " ";
        }
        cout << endl;
    }
    return 0;
}