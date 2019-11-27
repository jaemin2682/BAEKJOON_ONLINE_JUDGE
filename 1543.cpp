#include <iostream>
#include <string>

using namespace std;

string docu, word;
int ans;

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    getline(cin, docu);
    getline(cin, word);

    int docuSize = docu.size(), wordSize = word.size();
    for(int i=0;i<docuSize-wordSize+1;i++) {
        if(docu[i] == word[0]) {
            bool IsRight = true;
            for(int j=1;j<wordSize;j++) {
                if(docu[i+j] != word[j]) {
                    IsRight = false;
                    break;
                }
            }
            if(IsRight) {
                ans++;
                i = i + wordSize - 1;
            }
        }
    }
    cout << ans;

    return 0;
}

/*
단어의 첫글자와 일치하면 뒤를 탐색해서 맞는지 확인하고, 맞다면 cnt를 올리고 i를 전진시킨다.
*/