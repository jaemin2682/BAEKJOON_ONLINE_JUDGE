#include <iostream>

using namespace std;

int main() {
    int t;
    cin >> t;
    for(int i=0;i<t;i++) {
        int n;
        double total=0, sum=0;
        cin >> n;
        for(int j=0;j<n;j++) {
            double c, g;
            cin >> c >> g;
            total += c;
            sum += c*g;
        }
        printf("%.0f %.1f\n", total, sum/total);
    }

    return 0;
}