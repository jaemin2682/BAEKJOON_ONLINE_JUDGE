#include <iostream>
#include <string>
#include <vector>
using namespace std;

string variable_name;
vector<string> word;
bool is_error, is_cpp, is_java, is_under, is_upper;
int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin >> variable_name;
    int size = variable_name.size();

    //첫글자가 대문자나 '_', 마지막이 '_'면 오류
    if((variable_name[0] >= 'A' && variable_name[0] <= 'Z') 
    || variable_name[0] == '_' || variable_name[size-1] == '_') {    
        cout << "Error!";
        return 0;
    }

    for(int i=0;i<size;i++) { //언더바, 대문자 체크. '_'가 2연속시 에러
        if(variable_name[i] == '_') is_under = true;
        else if(variable_name[i] >= 'A' && variable_name[i] <= 'Z') is_upper = true;
        if(variable_name[i] == '_' && variable_name[i+1]=='_') is_error = true;
    }

    if((is_upper && is_under) || is_error) {  //'_'와 대문자가 공존할 수 없다.
        cout << "Error!";
        return 0;
    }

    string temp;
    if(is_upper) {  // 대문자 존재 -> Java
        is_java = true;
        for(int i=0;i<size;i++) {
            if(variable_name[i] >= 'A' && variable_name[i] <= 'Z') {
                word.push_back(temp);
                temp = "";
            }
            temp += variable_name[i];
        }
        word.push_back(temp);
    }
    else if(is_under) {  //언더바 존재 -> C++
        is_cpp = true;
        for(int i=0;i<size;i++) {
            if(variable_name[i] == '_') {
                word.push_back(temp);
                temp = "";
            }
            else temp += variable_name[i];
        }
        word.push_back(temp);
    }
    else {  //대문자도, 언더바도 없다 : 한 단어로 이루어졌다.(java, c++ 상관 X)
        cout << variable_name;
    }
    //출력부
    int word_size = word.size();
    if(is_java) {   //java이므로 c++로 출력
        for(int i=0;i<word_size-1;i++) {
            if(word[i][0] >= 'A' && word[i][0] <= 'Z') word[i][0] += 32;
            cout << word[i] << '_';
        }
        word[word_size-1][0] += 32;
        cout << word[word_size-1];
    }
    else if(is_cpp) {   //cpp이므로 java로 출력
        cout << word[0];
        for(int i=1;i<word_size;i++) {
            word[i][0] -=32;
            cout << word[i];
        }
    }
    
    return 0;
}
/*
Java : 첫 단어는 소문자, 다음 단어부터는 첫 문자만 대문자로 사용, 모든 단어를 붙여 씀
C++ : 소문자만 사용, 단어와 단어 사이에 '_' 사용

먼저 Java의 변수명인지 C++의 변수명인지 확인한다.
반대로 바꿔준다.

c++의 경우, _가 있다. 하지만 대문자가 같이있으면 오류이다.
java의 경우, 맨 첫글자가 대문자일 수 없다. c++도 마찬가지기 때문에, 첫글자가 대문자면 오류이다.

예외처리가 너무 많아서 몇번 틀렸다...
맨 뒤에 _가 나오는 경우, 맨 앞에 _가 나오는 경우, _가 2번 이상 나오는 경우 등.
어쨌든 AC!
*/