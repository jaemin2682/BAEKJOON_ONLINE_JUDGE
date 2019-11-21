#include <iostream>
#include <string>

using namespace std;

int main() {
    string str;
    cin >> str;
    int left=0, right=0, idx;
    for(int i=0;i<str.size();i++) {
        if(str[i] == '@') left++;
        else if(str[i] == '(') {
            idx = i;
            break;
        }
    }
    for(int i=idx+5;i<str.size();i++) {
        if(str[i]=='@') right++;
    }
    cout << left << " " << right;

    return 0;
}

/*
그냥 @의 개수를 세는 문제이다.
*/