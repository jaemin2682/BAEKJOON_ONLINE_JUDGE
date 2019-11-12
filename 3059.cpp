#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <memory.h>
#include <math.h>
#include <set>

using namespace std;

int main() {
	bool check[27];
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		int sum = 0;
		string str;
		cin >> str;
		memset(check, false, sizeof(check));
		for (int j = 0; j < str.size(); j++) check[str[j] - 64] = true;
		for (int j = 1; j <= 26; j++)
			if (!check[j]) sum += j + 64;
		cout << sum << endl;
	}
	return 0;
}