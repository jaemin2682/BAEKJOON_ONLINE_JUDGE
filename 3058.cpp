#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <memory.h>

using namespace std;

int main() {
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		int sum = 0, minval = 101;
		for (int j = 0; j < 7; j++) {
			int num;
			cin >> num;
			if (num % 2 == 0) {
				sum += num;
				minval = min(minval, num);
			}
		}
		cout << sum << " " << minval << endl;
	}

	return 0;
}