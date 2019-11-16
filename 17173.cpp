#include <iostream>
#include <set>
#include <vector>

using namespace std;

int main() {
    int n, m, sum=0;
    cin >> n >> m;
    set<int> s;

    for(int i=0;i<m;i++) {
        int num;
        cin >> num;
        for(int j=1;num*j <= n;j++) {
            s.insert(num*j);
        }
    }
    set<int> :: iterator iter;
    for(iter = s.begin();iter!=s.end();iter++) {
        sum += *iter;
    }
    cout << sum;

    return 0;
}