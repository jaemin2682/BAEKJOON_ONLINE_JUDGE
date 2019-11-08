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
		vector<string> list;
		cin >> n;
		int check = n;
		for (int j = 0; j < n; j++) {
			string str;
			cin >> str;
			if (str[0] >= 'a' && str[0] <= 'z') check = j;
			list.push_back(str);
		}

		for (int a = check + 1; a < n; a++) {
			cout << list[a] << " ";
		}
		if(check < n) cout << list[check] << " ";
		for (int b = 0; b < check; b++) {
			cout << list[b] << " ";
		}

		cout << endl;
	}

	return 0;
}

