#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <memory.h>

using namespace std;

int main() {
	int t, sum;
	cin >> t;
	for (int i = 0; i < t; i++) {
		int s, n;
		cin >> s >> n;
		sum = s;
		for (int j = 0; j < n; j++) {
			int p, q;
			cin >> p >> q;
			sum += p * q;
		}
		cout << sum << endl;
	}

	return 0;
}