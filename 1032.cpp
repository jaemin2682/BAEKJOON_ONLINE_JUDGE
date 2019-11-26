#include <iostream>
#include <string>

using namespace std;

int N;
string str, store;

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    for(int i=0;i<N;i++) {
        cin >> str;
        if(i==0) {
            store = str;
            continue;
        }
        
        for(int a = str.size()-1;a>=0;a--) {
            if(store[a] != str[a]) store[a] = '?';
        }
    }
    cout << store;

    return 0;
}
/*
첫 입력을 저장하고, 이후 입력부터 비교하여 다른 부분은 ?를 채운다.
*/