#include <iostream>

using namespace std;

int main() {
    int t;
    cin >> t;
    for(int i=0;i<t;i++) {
        int n, cnt=0;
        double d;
        cin >> n >> d;
        for(int j=0;j<n;j++) {
            double v, f, c;
            cin >> v >> f >> c;
            double time = d / v;
            if(c * time <= f) cnt++;
            // d / v : 가는데 걸리는 시간
            // c * 걸리는시간 >= f인 것의 개수.
        }
        cout << cnt << endl;
    }

    return 0;
}