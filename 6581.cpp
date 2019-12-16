#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<string> word;

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    while(1) {  //단어를 다 모은다.
        string str;
        cin >> str;
        if(cin.eof()) break;
        word.push_back(str);
    }
    int wordSize = word.size(), lineSize=0;
    for(int i=0;i<wordSize;i++) {   //각 단어를 확인
        if(word[i] == "<br>") { //<br>태그를 받으면 개행
            cout <<'\n';  
            lineSize = 0;
        }
        else if(word[i] == "<hr>") {    //<hr>태그를 받고 행의 처음이 아니면 -출력
            if(lineSize!=0) {
                cout << '\n';
                for(int j=0;j<16;j++) cout << "-----";
                cout << '\n';
                lineSize = 0;
            }
            else {
                for(int j=0;j<16;j++) cout << "-----";
                cout << '\n';
                lineSize = 0;
            }
        }
        else if(lineSize + word[i].size() <= 80)  { //합쳐도 80글자 안되면 출력
            cout << word[i] << " ";
            lineSize += word[i].size() + 1; //line Size 더해줌
        }
        else {  //80글자가 넘어가면, 개행 후 출력
            cout << '\n' << word[i] << " ";
            lineSize = word[i].size() + 1;
        }
    }

    cout << '\n';

    return 0;
}
/*
조건
1. 단어는 연속된 알파벳,숫자,문장 부호들이며 띄어쓰기로 구분한다.
2. 여러 개의 개행 문자, 띄어쓰기, 공백, 탭은 하나의 공백문자로 출력함
3. 이번에 출력할 단어를 포함하여 80글자 이내면 현재줄 출력, 넘으면 새로운줄에 출력한다.
4. <br>를 읽으면 새 줄을 시작한다.
5. <hr>를 읽는데 줄의 첫 부분이 아니라면, 새 줄을 시작해 '-'를 80글자 입력, 다시 새 줄 시작
6. 마지막 줄은 개행 문자로 끝난다.

태그도 공백문자 사이로 주어지므로, 모든 단어를 입력받아 모은다.
각 단어를 출력해주며 한칸씩 띄어주면 된다. (80글자 체크하면서, 태그 체크하면서)
-> AC
*/