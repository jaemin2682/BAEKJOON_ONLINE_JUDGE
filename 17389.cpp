#include <iostream>
#include <string>

using namespace std;

int main() {
    int n;
    cin >> n;
    string str;
    cin >> str;

    int score=0, bonus=0;
    for(int i=0;i<str.size();i++) {
        if(str[i] == 'O') {
            score += i+1+bonus;
            bonus++;
        }
        else bonus=0;
    }
    cout << score;

    return 0;
}