#include <iostream>
#include <string>
#include <memory.h>

using namespace std;

int main() {
    while(1) {
        string str;
        getline(cin, str);
        if(str=="*") return 0;
        bool alpha[26];
        memset(alpha, false, sizeof(alpha));

        for(int i=0;i<str.size();i++) { //사용한 알파벳 표시
            alpha[str[i]-'a'] = true;
        }
        bool check = true;
        for(int i=0;i<26;i++) {
            if(!alpha[i]) {
                check = false;
                cout << "N" << endl;
                break;
            }
        }
        if(check) cout << "Y" << endl;
    }
    return 0;
}