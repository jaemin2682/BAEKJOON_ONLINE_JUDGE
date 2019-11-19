#include <iostream>
#include <string>

using namespace std;

int main() {
    while(1) {
        string str;
        getline(cin, str);
        if(str=="#") break;
        int sum = 0;
        for(int i=0;i<str.size();i++) {
            if(str[i] == ' ') continue;
            sum += (i+1)*(str[i] - 'A' + 1);
        }
        cout << sum << endl;
    }


    return 0;
}