#include <iostream>
#include <string>

using namespace std;

int main() {
    int n, score=0;
    cin >> n;
    string str;
    cin >> str;
    for(int i=0;i<str.size();i++) {
        score += str[i] - 'A' + 1;
    }
    cout << score;
    

    return 0;
}