#include <iostream>

using namespace std;

int main() {    //MST. 노드개수 - 1
    int t;
    cin >> t;
    for(int i=0;i<t;i++) {
        int n, m;
        cin >> n >> m;
        for(int j=0;j<m;j++) {
            int a, b;
            cin >> a >> b;
        }
        cout << n-1 << endl;
    }

    return 0;
}