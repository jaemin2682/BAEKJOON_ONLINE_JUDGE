#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <memory.h>
#include <math.h>

using namespace std;

int main() {
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		int n;
		cin >> n;
		string strRes;
		int intRes = 0;
		for (int j = 0; j < n; j++) {
			string str;
			int drink;
			cin >> str >> drink;
			if (drink > intRes) {
				strRes = str;
				intRes = drink;
			}
		}
		cout << strRes << endl;
	}

	return 0;
}