#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <memory.h>
#include <math.h>

using namespace std;

int main() {
	string str;
	cin >> str;
	for (int i = 0; i < str.size(); i++) {
		if (str[i] < 'D') str[i] += 23;
		else str[i] -= 3;
	}
	cout << str;
	return 0;
}