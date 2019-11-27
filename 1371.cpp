#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int alphabet[26];
string str;

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    while(1) {
        cin >> str;
        if(cin.eof()) break;

        int size = str.size();
        for(int i=0;i<size;i++) 
            alphabet[str[i]-'a']++;
    }
    
    int maxVal=0;
    for(int i=0;i<26;i++) maxVal = max(maxVal, alphabet[i]);
    
    
    for(int i=0;i<26;i++) {
        char alpha = 'a' + i;
        if(alphabet[i] == maxVal) cout << alpha;
    }
    return 0;
}
/*
입력이 몇줄에 달할저도로 길었지만, 어차피 띄어쓰기나 엔터로 구분되어진 문자열들이었기 때문에
반복해서 string으로 단어들을 입력받았다.
그리고 각 철자의 누적개수를 저장해 가장 큰 누적개수와 같은 알파벳들을 출력했다. -> AC
*/