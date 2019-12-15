#include <iostream>
#include <string>
#include <map>
using namespace std;

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    while(1) {
        string str;
        cin >> str;
        if(str == "*") break;   //종료 조건
        
        int strSize = str.size();
        bool isSurprising = true;
        for(int d=1;d<strSize;d++) {  //각 d- 쌍(거리)
            map<string, int> m;
            for(int j = 0;j<strSize-d;j++) {//쌍을 구할 원소
                string temp = "";
                temp += str[j];
                temp += str[j+d];
                if(m.find(temp) != m.end()) {   //map에 이미 있으면 non surprising
                    isSurprising = false;
                    break;
                }
                m[temp] = d;    //map에 추가해줌
            }
            if(!isSurprising) break;
        }
        cout << str;    //출력부
        if(isSurprising) cout << " is surprising.\n";
        else cout << " is NOT surprising.\n";
    }
    return 0;
}
/*
문자열의 0-쌍~ (N-2)-쌍에 대해, 각 쌍들에 겹치는 문자가 없는지 찾으면 된다.
다른 쌍에 대해서는 같은 문자가 있어도 된다.

*/