#include <iostream>

using namespace std;

int A[100][100];
int B[100][100];
int res[100][100];

int main() {    
    int n, m;
    cin >> n >> m;
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            cin >> A[i][j];

    int k;
    cin >> m >> k;
    for(int i=0;i<m;i++)
        for(int j=0;j<k;j++)
            cin >> B[i][j];
    
    for(int i=0;i<n;i++) {
        for(int j=0;j<k;j++) {
            int num = 0;
            for(int a=0;a<m;a++) {
                num += A[i][a] * B[a][j];
            }
            res[i][j] = num;
        }
    }

    for(int i=0;i<n;i++) {
        for(int j=0;j<k;j++) {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
