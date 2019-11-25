#include <iostream>
#include <string>

using namespace std;

int first[26], second[26];

int main() {
    string str1, str2;
    cin >> str1 >> str2;
    for(int i=0;i<str1.size();i++) first[str1[i]-'a']++;
    for(int i=0;i<str2.size();i++) second[str2[i]-'a']++;

    int sum = 0;
    for(int i=0;i<26;i++) {
        if(first[i] != second[i]) sum += abs(first[i]-second[i]);
    }
    cout << sum;

    return 0;
}
/*
제거해야 하는 문자는 결국 배열에 나타난 문자 빈도를 나타내었을 때, 두 배열의 차이이다.
*/