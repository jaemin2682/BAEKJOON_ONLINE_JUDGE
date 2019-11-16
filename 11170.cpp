#include <iostream>
#include <string>

using namespace std;

int main() {
    int t;
    cin >> t;
    for(int i=0;i<t;i++) {
        string a, b;
        int cnt = 0;
        cin >> a >> b;
        int IA = stoi(a), IB = stoi(b);
        for(int j=IA;j<=IB;j++) {
            string tem = to_string(j);
            for(int k=0;k<tem.size();k++) {
                if(tem[k] == '0') cnt++;
            }
        }
        cout << cnt << endl;
    }

    return 0;
}