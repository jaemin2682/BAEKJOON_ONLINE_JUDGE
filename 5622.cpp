#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <memory.h>

using namespace std;

int main() {
	string str;
	int res = 0;
	cin >> str;

	for (int i = 0; i < str.size(); i++) {
		if (str[i] <= 'C') res += 3;
		else if (str[i] <= 'F') res += 4;
		else if (str[i] <= 'I') res += 5;
		else if (str[i] <= 'L') res += 6;
		else if (str[i] <= 'O') res += 7;
		else if (str[i] <= 'S') res += 8;
		else if (str[i] <= 'V') res += 9;
		else if (str[i] <= 'Z') res += 10;
	}

	cout << res;

	return 0;
}