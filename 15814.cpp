#include <iostream>
#include <string>

using namespace std;

int main() {
    string str;
    cin >> str;
    int t;
    cin >> t;
    for(int i=0;i<t;i++) {
        int a, b;
        cin >> a >> b;
        swap(str[a], str[b]);
    }
    cout << str;
    return 0;
}