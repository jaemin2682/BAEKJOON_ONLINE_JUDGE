#include <iostream>
#include <set>

using namespace std;

int n;

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    set<int> s;
    for(int i=0;i<n;i++) {
        int num;
        cin >> num;
        s.insert(num);
    }
    set<int> :: iterator iter;
    for(iter = s.begin();iter!=s.end();iter++) cout << *iter << " "; 

    return 0;
}