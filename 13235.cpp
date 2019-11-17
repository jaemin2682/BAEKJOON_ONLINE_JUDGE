#include <iostream>
#include <string>

using namespace std;

int main() {
    string str;
    cin >> str;
    int size = str.size();
    bool check = true;
    for(int i=0;i<size/2;i++) {
        if(str[i] != str[size-1-i]) {
            check = false;
            break;
        }
    }
    
    if(check) cout << "true";
    else cout << "false";

    return 0;
}