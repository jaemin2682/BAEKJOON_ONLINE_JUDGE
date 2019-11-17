#include <iostream>
#include <string>
#include <memory.h>

using namespace std;

int main() {
    while(1) {
        string str;
        getline(cin, str);
        if(str == "#") break;
        bool alpha[26];
        memset(alpha, false, sizeof(alpha));
        for(int i=0;i<str.size();i++) {
            if(str[i] >= 'a' && str[i] <= 'z') alpha[str[i]-'a'] = true;
            else if(str[i] >= 'A' && str[i] <= 'Z') alpha[str[i] - 'A'] = true;
        }
        int sum=0;
        for(int i=0;i<26;i++)
            if(alpha[i]) sum++;
        cout << sum << endl;
    }

    return 0;
}