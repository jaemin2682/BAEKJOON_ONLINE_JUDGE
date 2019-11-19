#include <iostream>

using namespace std;

long long route[1001][1001];

int main() {
    int n, m;
    cin >> n >> m;
    route[1][1] = 1;
    for(int i=2;i<=1000;i++) {
        route[i][1] = 1;
        route[1][i] = 1;
    }
    for(int i=2;i<=1000;i++) {
        for(int j=2;j<=1000;j++) {
            route[i][j] = (route[i-1][j] + route[i][j-1] + route[i-1][j-1]) % 1000000007;
        }
    }

    cout << route[n][m];

    return 0;
}