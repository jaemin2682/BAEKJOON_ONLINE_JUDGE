#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    for(int i=0;i<n;i++) {
        if(i%2==1) cout << " ";
        for(int j=0;j<n;j++) {
            cout << "* ";
        }
        cout << endl;
    }

    return 0;
}
// 예시를 보고 규칙을 파악해서 풀면 된다.