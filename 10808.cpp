#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <memory.h>

using namespace std;

int main() {
	string str;
	cin >> str;
	int alphabet[26];
	memset(alphabet, false, sizeof(alphabet));
	for (int i = 0; i < str.size(); i++) {
		alphabet[str[i] - 97]++;
	}
	for (int i = 0; i < 26; i++) cout << alphabet[i] << ' ';
	return 0;
}