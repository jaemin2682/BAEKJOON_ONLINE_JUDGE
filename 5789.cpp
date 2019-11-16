#include <iostream>
#include <string>

using namespace std;

int main() {
    int n;
    cin >> n;
    for(int i=0;i<n;i++) {
        string str;
        cin >> str;
        if(str[str.size()/2-1] == str[str.size()/2]) cout << "Do-it" << endl;
        else cout << "Do-it-Not" << endl;
    }
    return 0;
}