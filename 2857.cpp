#include <iostream>
#include <string>
using namespace std;

string name, ans;
int cnt;

int main() {
    for(int i=0;i<5;i++) {
        cin >> name;
        int size = name.size();
        for(int j=0;j<size-2;j++) {
            if(name[j] == 'F') {
                if(name[j+1] == 'B' && name[j+2] == 'I') {
                    ans += to_string(i+1) + " ";
                    cnt++;
                    break;
                }
            }
        }
    }
    if(!cnt) cout << "HE GOT AWAY!";     
    else cout << ans;
    return 0;
}
/*
FBI가 포함되어 있는지 체크하고, 있으면 인덱스를 저장하고 출력한다. 없으면 다른 문자열을 출력한다.
*/