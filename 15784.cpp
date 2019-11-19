#include <iostream>

using namespace std;

int attrac[1000+1][1000+1];

int main() {
    int n, a, b;
    cin >> n >> a >> b;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            cin >> attrac[i][j];
    
    bool IsAngry = false;
    for(int i=1;i<=n;i++) {
        if(attrac[a][i] > attrac[a][b]) {
            IsAngry = true; 
            break;
        }
    }
    if(!IsAngry) {
        for(int i=1;i<=n;i++) {
            if(attrac[i][b] > attrac[a][b]) {
                IsAngry = true;
                break;
            }
        }
    }

    if(IsAngry) cout << "ANGRY";
    else cout << "HAPPY";

    return 0;
}