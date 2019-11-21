#include <iostream>
#include <string>

using namespace std;

int main() {
    string str;
    cin >> str;
    int dif = str[0]-str[1];
    bool IsRight = true;
    for(int i=0;i<str.size()-1;i++) {
        if(str[i]-str[i+1] != dif) {
            IsRight = false;
            break;
        }
    }

    if(IsRight) cout << "◝(⑅•ᴗ•⑅)◜..°♡ 뀌요미!!";
    else cout << "흥칫뿡!! <(￣ ﹌ ￣)>";


    return 0;
}
/*
각 자릿수의 차가 일정하느냐 아니냐를 판단해야 한다.
스트링으로 받아서 각 자리수의 차를 비교해주면 되겠다. -> AC
*/