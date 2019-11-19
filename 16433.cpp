#include <iostream>

using namespace std;

bool area[100][100];

int main() {
    int n, r, c;
    cin >> n >> r >> c;
    bool odd;
    if((r+c) % 2 == 0) odd = false;
    else odd = true;

    for(int i=1;i<=n;i++) {
        for(int j=1;j<=n;j++) {
            if(odd) {
                if((i+j)%2==1) area[i][j] = true;
            }
            else {
                if((i+j)%2==0) area[i][j] = true;
            }
        }
    }

    for(int i=1;i<=n;i++) {
        for(int j=1;j<=n;j++) {
            if(area[i][j]) cout << 'v';
            else cout << '.';
        }
        cout << endl;
    }

    return 0;
}