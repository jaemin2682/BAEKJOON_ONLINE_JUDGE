#include <iostream>
#include <string>
#include <vector>
#include <memory.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    for(int i=0;i<t;i++) {
        int n;
        cin >> n;
        vector<string> key1(n), key2(n), secretkey(n);
        int rule[1000];
        memset(rule, 0, sizeof(rule));
        for(int j=0;j<n;j++) cin >> key1[j];
        for(int j=0;j<n;j++) cin >> key2[j];
        for(int j=0;j<n;j++) cin >> secretkey[j];

        for(int j=0;j<n;j++) {
            for(int k=0;k<n;k++) {
                if(key2[j] == key1[k]) {
                    rule[j] = k;
                    break;
                }
            }
        }

        for(int j=0;j<n;j++) {
            for(int k=0;k<n;k++) {
                if(rule[k] == j) { 
                    cout << secretkey[k] << " ";
                    break;
                }
            }
        }
        cout << endl;
    }


    return 0;
}