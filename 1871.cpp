#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <memory.h>
#include <math.h>

using namespace std;

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		string str;
		int valueA = 0, valueB = 0;
		cin >> str;
		for (int i = 0; i <= 2; i++) valueA += (str[i] - 65)*pow(26, 2 - i);
		for (int i = 4; i <= 7; i++) valueB += (str[i] - '0') * pow(10, 7 - i);
		
		if (abs(valueA - valueB) > 100) cout << "not nice" << endl;
		else cout << "nice" << endl;
	}

	return 0;
}