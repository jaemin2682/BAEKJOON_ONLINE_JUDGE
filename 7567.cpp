#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <memory.h>

using namespace std;

int main() {
	string str;
	cin >> str;
	int height = 10;
	for (int i = 1; i < str.size(); i++) {
		if (str[i] == str[i - 1]) height += 5;
		else height += 10;
	}
	cout << height;

	return 0;
}