#include <iostream>
#include <string>
using namespace std;

string standard, key;

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    getline(cin, standard);
    cin >> key;

    int size = standard.size(), keysize = key.size();
    
    for(int i=0;i<size;i++) {
        char tem = standard[i];
        if(tem >= 'a' && tem <= 'z') {
            if(standard[i] - key[i%keysize] + 'a' - 1 < 'a')
                standard[i] = standard[i] - key[i%keysize] + 'a' - 1 + 26;
            else standard[i] = standard[i] - key[i%keysize] + 'a' - 1;
        }
    }
    cout << standard;

    return 0;
}

/*
a(1) ~ z(26)을 나타내고, 평문에서 암호화 키를 뺀 문자가 암호문이다.
a보다 작아질 경우 다시 z로 돌아가서 빼도록 한다. 띄어쓰기는 그대로 출력한다.
띄어쓰기도 암호화 키의 인덱스를 가져간다.
*/