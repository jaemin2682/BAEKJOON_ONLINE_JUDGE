#include <iostream>
#include <string>

using namespace std;

int main() {
    int n;
    string str;
    cin >> n >> str;
    bool check = true;
    for(int i=0;i<str.size()-1;i++) {
        if(str[i] == str[i+1]) {
            check = false;
            break;
        }
    }

    if(check) cout << "Yes";
    else cout << "No";

    return 0;
}
/*
주저리 주저리 써져있지만, 결국 같은 수가 연속으로 나오지 않으면 되는것이다.

*/