#include <iostream>
#include <string>

using namespace std;

int main() {
    int n;
    cin >> n;
    cin.ignore();
    for(int i=0;i<n;i++) {
        string hobby;
        getline(cin, hobby);
        int score=0;
        for(int i=0;i<hobby.size();i++) {
            if(hobby[i] >= 'A' && hobby[i] <= 'Z') {
                score += hobby[i] - 'A' + 1;
            }
        }
        if(score==100) cout << "PERFECT LIFE" << endl;
        else cout << score << endl;
        
    }
    return 0;
}
/*
공백을 포함한 문자열 입력과, cin.ignore()를 사용할 줄 아는 것 이외에는 별다르게 어려운
점은 없었다.
*/