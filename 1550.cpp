#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <memory.h>
#include <math.h>

using namespace std;

int main() {
	string str;
	int dec = 0;
	cin >> str;
	for (int i = 0; i < str.size(); i++) {
		int num;
		if (str[i] >= 'A' && str[i] <= 'F') {
			num = str[i] - 55;
		}
		else num = str[i] - 48;

		dec += num * pow(16, str.size() - i - 1);
	}
	cout << dec;
	return 0;
}