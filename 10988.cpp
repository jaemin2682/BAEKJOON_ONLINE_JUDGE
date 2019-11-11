#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <memory.h>

using namespace std;

int main() {
	string str;
	cin >> str;
	bool check = true;
	for (int i = 0; i < str.size() / 2; i++) {
		if (str[i] != str[str.size() - i - 1]) {
			check = false;
			break;
		}
	}
	if (check) cout << 1;
	else cout << 0;

	return 0;
}