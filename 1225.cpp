#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <memory.h>
#include <math.h>

using namespace std;

int main() {
	string str1, str2;
	long long res = 0;
	cin >> str1 >> str2;
	for (int i = 0; i < str1.size(); i++) {
		for (int j = 0; j < str2.size(); j++) {
			res += (str1[i] - 48) * (str2[j] - 48);
		}
	}
	cout << res;

	return 0;
}