#include <iostream>
#include <string>
#include <map>
using namespace std;

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    map<char, char> m;
    m.insert({'A', 'A'});
    m.insert({'E', '3'});
    m.insert({'H', 'H'});
    m.insert({'I', 'I'});
    m.insert({'J', 'L'});
    m.insert({'L', 'J'});
    m.insert({'M', 'M'});
    m.insert({'O', 'O'});
    m.insert({'S', '2'});
    m.insert({'T', 'T'});
    m.insert({'U', 'U'});
    m.insert({'V', 'V'});
    m.insert({'W', 'W'});
    m.insert({'X', 'X'});
    m.insert({'Y', 'Y'});
    m.insert({'Z', '5'});
    m.insert({'1', '1'});
    m.insert({'2', 'S'});
    m.insert({'3', 'E'});
    m.insert({'5', 'Z'});
    m.insert({'8', '8'});
    while(1) {
        string str;
        cin >> str;
        if(cin.eof()) break;
        bool ismirrored = true, ispalindrome = true;
        int strSize = str.size();

        if(strSize == 1) {
            if(m.find(str[0]) == m.end()) ismirrored = false;
        }
        else {
            for(int i=0;i<strSize/2;i++) {
                if(str[i] != str[strSize-1-i]) ispalindrome = false;

                if(m.find(str[i]) == m.end()) ismirrored = false;
                else {
                    if(m.find(str[i])->second != str[strSize-1-i]) ismirrored = false;
                }
            }
        }
        
        if(ispalindrome && ismirrored) cout << str << " -- is a mirrored palindrome.\n\n";
        else if(ispalindrome) cout << str << " -- is a palindrome.\n\n";
        else if(ismirrored) cout << str << " -- is a mirrored string.\n\n";
        else cout << str << " -- is not a palindrome.\n\n";
    }
    return 0;
}
/*
간단한 문자열 체크 문제였으나, 출력 시에 개행을 두번씩 해야돼는데 한번씩 하여
많은 실패를 했다..
*/