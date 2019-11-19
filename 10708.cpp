#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, m, fail;
    cin >> n >> m;
    vector<int> target(m);
    vector<int> score(n+1);
    for(int i=0;i<m;i++) cin >> target[i];
    for(int i=0;i<m;i++) {
        fail=0;
        for(int j=1;j<=n;j++) {
            int num;
            cin >> num;
            if(num == target[i]) score[j]++;
            else fail++;
        }
        score[target[i]] += fail;
    }
    for(int i=1;i<=n;i++) cout << score[i] << endl;
    
    return 0;
}