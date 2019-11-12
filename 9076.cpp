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
		vector<int> list(5);
		for (int j = 0; j < 5; j++) cin >> list[j];
		sort(list.begin(), list.end());
		if (list[3] - list[1] >= 4) cout << "KIN" << endl;
		else cout << list[1] + list[2] + list[3] << endl;
	}

	return 0;
}